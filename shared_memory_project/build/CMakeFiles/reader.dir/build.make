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
CMAKE_SOURCE_DIR = /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build

# Include any dependencies generated for this target.
include CMakeFiles/reader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reader.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reader.dir/flags.make

CMakeFiles/reader.dir/src/reader.c.o: CMakeFiles/reader.dir/flags.make
CMakeFiles/reader.dir/src/reader.c.o: /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/src/reader.c
CMakeFiles/reader.dir/src/reader.c.o: CMakeFiles/reader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/reader.dir/src/reader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/reader.dir/src/reader.c.o -MF CMakeFiles/reader.dir/src/reader.c.o.d -o CMakeFiles/reader.dir/src/reader.c.o -c /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/src/reader.c

CMakeFiles/reader.dir/src/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/reader.dir/src/reader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/src/reader.c > CMakeFiles/reader.dir/src/reader.c.i

CMakeFiles/reader.dir/src/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/reader.dir/src/reader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/src/reader.c -o CMakeFiles/reader.dir/src/reader.c.s

# Object files for target reader
reader_OBJECTS = \
"CMakeFiles/reader.dir/src/reader.c.o"

# External object files for target reader
reader_EXTERNAL_OBJECTS =

reader: CMakeFiles/reader.dir/src/reader.c.o
reader: CMakeFiles/reader.dir/build.make
reader: CMakeFiles/reader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable reader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reader.dir/build: reader
.PHONY : CMakeFiles/reader.dir/build

CMakeFiles/reader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reader.dir/clean

CMakeFiles/reader.dir/depend:
	cd /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build /home/hoang/sharedMemory/LTHT/DoAnLTHT/shared_memory_project/build/CMakeFiles/reader.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/reader.dir/depend

