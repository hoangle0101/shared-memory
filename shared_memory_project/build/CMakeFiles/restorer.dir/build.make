# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/hoang/sharedMemory/LTHT1/shared_memory_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hoang/sharedMemory/LTHT1/shared_memory_project/build

# Include any dependencies generated for this target.
include CMakeFiles/restorer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/restorer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/restorer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/restorer.dir/flags.make

CMakeFiles/restorer.dir/src/restorer.c.o: CMakeFiles/restorer.dir/flags.make
CMakeFiles/restorer.dir/src/restorer.c.o: /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/restorer.c
CMakeFiles/restorer.dir/src/restorer.c.o: CMakeFiles/restorer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hoang/sharedMemory/LTHT1/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/restorer.dir/src/restorer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/restorer.dir/src/restorer.c.o -MF CMakeFiles/restorer.dir/src/restorer.c.o.d -o CMakeFiles/restorer.dir/src/restorer.c.o -c /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/restorer.c

CMakeFiles/restorer.dir/src/restorer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/restorer.dir/src/restorer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/restorer.c > CMakeFiles/restorer.dir/src/restorer.c.i

CMakeFiles/restorer.dir/src/restorer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/restorer.dir/src/restorer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/restorer.c -o CMakeFiles/restorer.dir/src/restorer.c.s

# Object files for target restorer
restorer_OBJECTS = \
"CMakeFiles/restorer.dir/src/restorer.c.o"

# External object files for target restorer
restorer_EXTERNAL_OBJECTS =

restorer: CMakeFiles/restorer.dir/src/restorer.c.o
restorer: CMakeFiles/restorer.dir/build.make
restorer: CMakeFiles/restorer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hoang/sharedMemory/LTHT1/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable restorer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/restorer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/restorer.dir/build: restorer
.PHONY : CMakeFiles/restorer.dir/build

CMakeFiles/restorer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/restorer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/restorer.dir/clean

CMakeFiles/restorer.dir/depend:
	cd /home/hoang/sharedMemory/LTHT1/shared_memory_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hoang/sharedMemory/LTHT1/shared_memory_project /home/hoang/sharedMemory/LTHT1/shared_memory_project /home/hoang/sharedMemory/LTHT1/shared_memory_project/build /home/hoang/sharedMemory/LTHT1/shared_memory_project/build /home/hoang/sharedMemory/LTHT1/shared_memory_project/build/CMakeFiles/restorer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/restorer.dir/depend

