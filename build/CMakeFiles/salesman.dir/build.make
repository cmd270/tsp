# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mindmirage/code/c/salesman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mindmirage/code/c/salesman/build

# Include any dependencies generated for this target.
include CMakeFiles/salesman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/salesman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/salesman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/salesman.dir/flags.make

CMakeFiles/salesman.dir/salesman.cpp.o: CMakeFiles/salesman.dir/flags.make
CMakeFiles/salesman.dir/salesman.cpp.o: /home/mindmirage/code/c/salesman/salesman.cpp
CMakeFiles/salesman.dir/salesman.cpp.o: CMakeFiles/salesman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mindmirage/code/c/salesman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/salesman.dir/salesman.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/salesman.dir/salesman.cpp.o -MF CMakeFiles/salesman.dir/salesman.cpp.o.d -o CMakeFiles/salesman.dir/salesman.cpp.o -c /home/mindmirage/code/c/salesman/salesman.cpp

CMakeFiles/salesman.dir/salesman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/salesman.dir/salesman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mindmirage/code/c/salesman/salesman.cpp > CMakeFiles/salesman.dir/salesman.cpp.i

CMakeFiles/salesman.dir/salesman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/salesman.dir/salesman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mindmirage/code/c/salesman/salesman.cpp -o CMakeFiles/salesman.dir/salesman.cpp.s

# Object files for target salesman
salesman_OBJECTS = \
"CMakeFiles/salesman.dir/salesman.cpp.o"

# External object files for target salesman
salesman_EXTERNAL_OBJECTS =

salesman: CMakeFiles/salesman.dir/salesman.cpp.o
salesman: CMakeFiles/salesman.dir/build.make
salesman: CMakeFiles/salesman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mindmirage/code/c/salesman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable salesman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/salesman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/salesman.dir/build: salesman
.PHONY : CMakeFiles/salesman.dir/build

CMakeFiles/salesman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/salesman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/salesman.dir/clean

CMakeFiles/salesman.dir/depend:
	cd /home/mindmirage/code/c/salesman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mindmirage/code/c/salesman /home/mindmirage/code/c/salesman /home/mindmirage/code/c/salesman/build /home/mindmirage/code/c/salesman/build /home/mindmirage/code/c/salesman/build/CMakeFiles/salesman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/salesman.dir/depend
