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
include CMakeFiles/searcher.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/searcher.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/searcher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/searcher.dir/flags.make

CMakeFiles/searcher.dir/src/searcher.c.o: CMakeFiles/searcher.dir/flags.make
CMakeFiles/searcher.dir/src/searcher.c.o: /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/searcher.c
CMakeFiles/searcher.dir/src/searcher.c.o: CMakeFiles/searcher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hoang/sharedMemory/LTHT1/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/searcher.dir/src/searcher.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/searcher.dir/src/searcher.c.o -MF CMakeFiles/searcher.dir/src/searcher.c.o.d -o CMakeFiles/searcher.dir/src/searcher.c.o -c /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/searcher.c

CMakeFiles/searcher.dir/src/searcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/searcher.dir/src/searcher.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/searcher.c > CMakeFiles/searcher.dir/src/searcher.c.i

CMakeFiles/searcher.dir/src/searcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/searcher.dir/src/searcher.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hoang/sharedMemory/LTHT1/shared_memory_project/src/searcher.c -o CMakeFiles/searcher.dir/src/searcher.c.s

# Object files for target searcher
searcher_OBJECTS = \
"CMakeFiles/searcher.dir/src/searcher.c.o"

# External object files for target searcher
searcher_EXTERNAL_OBJECTS =

searcher: CMakeFiles/searcher.dir/src/searcher.c.o
searcher: CMakeFiles/searcher.dir/build.make
searcher: CMakeFiles/searcher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hoang/sharedMemory/LTHT1/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable searcher"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/searcher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/searcher.dir/build: searcher
.PHONY : CMakeFiles/searcher.dir/build

CMakeFiles/searcher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/searcher.dir/cmake_clean.cmake
.PHONY : CMakeFiles/searcher.dir/clean

CMakeFiles/searcher.dir/depend:
	cd /home/hoang/sharedMemory/LTHT1/shared_memory_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hoang/sharedMemory/LTHT1/shared_memory_project /home/hoang/sharedMemory/LTHT1/shared_memory_project /home/hoang/sharedMemory/LTHT1/shared_memory_project/build /home/hoang/sharedMemory/LTHT1/shared_memory_project/build /home/hoang/sharedMemory/LTHT1/shared_memory_project/build/CMakeFiles/searcher.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/searcher.dir/depend

