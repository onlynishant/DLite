cmake_minimum_required(VERSION 3.6)
project(dlite)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  test/test_database.cpp)
add_executable(dlite ${SOURCE_FILES})

# Adding sqlite3
include_directories(../sqlite/sqlite_build)
link_directories(../sqlite/sqlite_build)
target_link_libraries(dlite sqlite3)

# Adding Boost
SET (BOOST_ROOT "../boost/boost_build")
SET (BOOST_INCLUDEDIR "../boost/boost_build/include")
SET (BOOST_LIBRARYDIR "../boost/boost_build/lib")
set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.63.0)
#find_package(Boost 1.63.0 COMPONENTS regex REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(dlite ${Boost_LIBRARIES})
endif()