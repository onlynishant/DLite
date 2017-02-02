//
// Created by Nishant Kumar on 02/02/17.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "sqlite3.h"

#define INPUTDATA "/Users/nishantkumar/Downloads/OpenData_TTC_Schedules/stop_times.txt"
#define DATABASE "../../sqlite/database/main.db"
#define DATABASE_REPLICA "/Users/nishantkumar/Downloads/sqlite_test/replica.db"
#define TABLE "CREATE TABLE IF NOT EXISTS TTC (id INTEGER PRIMARY KEY, Route_ID TEXT, Branch_Code TEXT, Version INTEGER, Stop INTEGER, Vehicle_Index INTEGER, Day Integer, Time TEXT)"
#define BUFFER_SIZE 256

using namespace std;

static int totalcount = 0;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\t", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    if(totalcount%1000==0)
        printf("count=%d\n",totalcount);

    printf("\n");
    ++totalcount;
    return 0;
}

int main(int argc, char **argv) {

    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sErrMsg = 0;
    char *tail = 0;
    int nRetCode;
    int n = 0;
    int limit = 1000000;
    int repetation = 1;
    bool doSelect = true;

    clock_t cStartClock;

    FILE *pFile;
    char sInputBuf[BUFFER_SIZE] = "\0";

    char *sRT = 0;  /* Route */
    char *sBR = 0;  /* Branch */
    char *sVR = 0;  /* Version */
    char *sST = 0;  /* Stop Number */
    char *sVI = 0;  /* Vehicle */
    char *sDT = 0;  /* Date */
    char *sTM = 0;  /* Time */

    char sSQL[BUFFER_SIZE] = "\0";

    /*********************************************/
    /* Open the Database and create the Schema */
    sqlite3_open(DATABASE, &db);
//
//    char * attachDB = "attach database '/Users/nishantkumar/Downloads/sqlite_test/replica.db' as replica";
//    int rc = sqlite3_exec(db, attachDB, NULL, NULL, &sErrMsg);
//    if (rc != SQLITE_OK ) {
//
//        fprintf(stderr, "Failed to attach database\n");
//        fprintf(stderr, "SQL error: %s\n", sErrMsg);
//
//        sqlite3_free(sErrMsg);
//    }

    sqlite3_exec(db, TABLE, NULL, NULL, &sErrMsg);
//    sqlite3_exec(db, "PRAGMA synchronous = OFF", NULL, NULL, &sErrMsg);
    //   sqlite3_exec(db, "PRAGMA journal_mode=WAL", NULL, NULL, &sErrMsg);
//    sqlite3_exec(db, "PRAGMA journal_mode = MEMORY", NULL, NULL, &sErrMsg);



    /*********************************************/
    /* Open input file and import into Database*/

    printf("SQLITE_THREADSAFE:%d\n",sqlite3_threadsafe());

    cStartClock = clock();

    sprintf(sSQL, "INSERT INTO TTC VALUES (NULL, @RT, @BR, @VR, @ST, @VI, @DT, @TM)");
    sqlite3_prepare_v2(db, sSQL, BUFFER_SIZE, &stmt, nullptr);

//    int rc = sqlite3_exec(db, "CREATE  INDEX 'TTC_route_Index' ON 'TTC' ('Route_ID')", NULL, NULL, &sErrMsg);
//    if (rc != SQLITE_OK ) {
//
//        fprintf(stderr, "Failed to create index\n");
//        fprintf(stderr, "SQL error: %s\n", sErrMsg);
//
//        sqlite3_free(sErrMsg);
//    }

    // check if autocommit enabled. default is enabled
    //printf("Autocommit: %d\n", sqlite3_get_autocommit(db));

    if (doSelect) {
        int rc = sqlite3_exec(db, "select * from TTC where Stop = 12345", callback, NULL, &sErrMsg);
        if (rc != SQLITE_OK ) {

            fprintf(stderr, "Failed to select data\n");
            fprintf(stderr, "SQL error: %s\n", sErrMsg);

            sqlite3_free(sErrMsg);
        }
        printf("count = %d\n",totalcount);
    } else {
        sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &sErrMsg);

        // Autocommit mode is disabled by a BEGIN statement and re-enabled by a COMMIT or ROLLBACK.
        // printf("Autocommit: %d\n", sqlite3_get_autocommit(db));

        pFile = fopen(INPUTDATA, "r");
        while (!feof(pFile)) {

            fgets(sInputBuf, BUFFER_SIZE, pFile);

            for (int i = 0; i < repetation; i++) {
                sRT = strtok(sInputBuf, ",");     /* Get Route */
                sBR = strtok(NULL, ",");            /* Get Branch */
                sVR = strtok(NULL, ",");            /* Get Version */
                sST = strtok(NULL, ",");            /* Get Stop Number */
                sVI = strtok(NULL, ",");            /* Get Vehicle */
                sDT = strtok(NULL, ",");            /* Get Date */
                sTM = strtok(NULL, ",");            /* Get Time */

                /* ACTUAL INSERT WILL GO HERE */

                //printf("%s %s %s %s %s %s\n",sRT,sBR, sVR,sST,sVI);
                sqlite3_bind_text(stmt, 1, sRT, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 2, sBR, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 3, sVR, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 4, sST, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 5, sVI, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 6, sDT, -1, SQLITE_STATIC);
                sqlite3_bind_text(stmt, 7, sTM, -1, SQLITE_STATIC);

                sqlite3_step(stmt);

                //sqlite3_clear_bindings(stmt);
                sqlite3_reset(stmt);

            }
            n++;

            if (n % 10000 == 0) {
                sqlite3_exec(db, "END TRANSACTION", NULL, NULL, &sErrMsg);
                sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &sErrMsg);
                //cout << "committed" << endl;
            }

            if (n > limit)
                break;
        }
        fclose(pFile);
        sqlite3_exec(db, "END TRANSACTION", NULL, NULL, &sErrMsg);
    }

    printf("Inserted %d records in %4.2f seconds\n", n, (clock() - cStartClock) / (double) CLOCKS_PER_SEC);

    sqlite3_close(db);
    return 0;
}


