# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bharan/computation/tutorials/mpi_tutorials/step_7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bharan/computation/tutorials/mpi_tutorials/step_7/build

# Include any dependencies generated for this target.
include CMakeFiles/step_7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/step_7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/step_7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/step_7.dir/flags.make

CMakeFiles/step_7.dir/step_7.cpp.o: CMakeFiles/step_7.dir/flags.make
CMakeFiles/step_7.dir/step_7.cpp.o: /home/bharan/computation/tutorials/mpi_tutorials/step_7/step_7.cpp
CMakeFiles/step_7.dir/step_7.cpp.o: CMakeFiles/step_7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bharan/computation/tutorials/mpi_tutorials/step_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/step_7.dir/step_7.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/step_7.dir/step_7.cpp.o -MF CMakeFiles/step_7.dir/step_7.cpp.o.d -o CMakeFiles/step_7.dir/step_7.cpp.o -c /home/bharan/computation/tutorials/mpi_tutorials/step_7/step_7.cpp

CMakeFiles/step_7.dir/step_7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/step_7.dir/step_7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bharan/computation/tutorials/mpi_tutorials/step_7/step_7.cpp > CMakeFiles/step_7.dir/step_7.cpp.i

CMakeFiles/step_7.dir/step_7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/step_7.dir/step_7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bharan/computation/tutorials/mpi_tutorials/step_7/step_7.cpp -o CMakeFiles/step_7.dir/step_7.cpp.s

# Object files for target step_7
step_7_OBJECTS = \
"CMakeFiles/step_7.dir/step_7.cpp.o"

# External object files for target step_7
step_7_EXTERNAL_OBJECTS =

step_7: CMakeFiles/step_7.dir/step_7.cpp.o
step_7: CMakeFiles/step_7.dir/build.make
step_7: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi_cxx.so
step_7: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
step_7: CMakeFiles/step_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bharan/computation/tutorials/mpi_tutorials/step_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable step_7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/step_7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/step_7.dir/build: step_7
.PHONY : CMakeFiles/step_7.dir/build

CMakeFiles/step_7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/step_7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/step_7.dir/clean

CMakeFiles/step_7.dir/depend:
	cd /home/bharan/computation/tutorials/mpi_tutorials/step_7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bharan/computation/tutorials/mpi_tutorials/step_7 /home/bharan/computation/tutorials/mpi_tutorials/step_7 /home/bharan/computation/tutorials/mpi_tutorials/step_7/build /home/bharan/computation/tutorials/mpi_tutorials/step_7/build /home/bharan/computation/tutorials/mpi_tutorials/step_7/build/CMakeFiles/step_7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/step_7.dir/depend

