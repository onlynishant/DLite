# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nishantkumar/DLite/dlite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nishantkumar/DLite/dlite/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/dlite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dlite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dlite.dir/flags.make

CMakeFiles/dlite.dir/test/test_database.cpp.o: CMakeFiles/dlite.dir/flags.make
CMakeFiles/dlite.dir/test/test_database.cpp.o: ../test/test_database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nishantkumar/DLite/dlite/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dlite.dir/test/test_database.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dlite.dir/test/test_database.cpp.o -c /Users/nishantkumar/DLite/dlite/test/test_database.cpp

CMakeFiles/dlite.dir/test/test_database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dlite.dir/test/test_database.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nishantkumar/DLite/dlite/test/test_database.cpp > CMakeFiles/dlite.dir/test/test_database.cpp.i

CMakeFiles/dlite.dir/test/test_database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dlite.dir/test/test_database.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nishantkumar/DLite/dlite/test/test_database.cpp -o CMakeFiles/dlite.dir/test/test_database.cpp.s

CMakeFiles/dlite.dir/test/test_database.cpp.o.requires:

.PHONY : CMakeFiles/dlite.dir/test/test_database.cpp.o.requires

CMakeFiles/dlite.dir/test/test_database.cpp.o.provides: CMakeFiles/dlite.dir/test/test_database.cpp.o.requires
	$(MAKE) -f CMakeFiles/dlite.dir/build.make CMakeFiles/dlite.dir/test/test_database.cpp.o.provides.build
.PHONY : CMakeFiles/dlite.dir/test/test_database.cpp.o.provides

CMakeFiles/dlite.dir/test/test_database.cpp.o.provides.build: CMakeFiles/dlite.dir/test/test_database.cpp.o


# Object files for target dlite
dlite_OBJECTS = \
"CMakeFiles/dlite.dir/test/test_database.cpp.o"

# External object files for target dlite
dlite_EXTERNAL_OBJECTS =

dlite: CMakeFiles/dlite.dir/test/test_database.cpp.o
dlite: CMakeFiles/dlite.dir/build.make
dlite: CMakeFiles/dlite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nishantkumar/DLite/dlite/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dlite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dlite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dlite.dir/build: dlite

.PHONY : CMakeFiles/dlite.dir/build

CMakeFiles/dlite.dir/requires: CMakeFiles/dlite.dir/test/test_database.cpp.o.requires

.PHONY : CMakeFiles/dlite.dir/requires

CMakeFiles/dlite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dlite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dlite.dir/clean

CMakeFiles/dlite.dir/depend:
	cd /Users/nishantkumar/DLite/dlite/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nishantkumar/DLite/dlite /Users/nishantkumar/DLite/dlite /Users/nishantkumar/DLite/dlite/cmake-build-release /Users/nishantkumar/DLite/dlite/cmake-build-release /Users/nishantkumar/DLite/dlite/cmake-build-release/CMakeFiles/dlite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dlite.dir/depend

