# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/hanna/Downloads/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/hanna/Downloads/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hanna/Documents/algorithm/fixed_set

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hanna/Documents/algorithm/fixed_set/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fixed_set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fixed_set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fixed_set.dir/flags.make

CMakeFiles/fixed_set.dir/main.cpp.o: CMakeFiles/fixed_set.dir/flags.make
CMakeFiles/fixed_set.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanna/Documents/algorithm/fixed_set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fixed_set.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fixed_set.dir/main.cpp.o -c /home/hanna/Documents/algorithm/fixed_set/main.cpp

CMakeFiles/fixed_set.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fixed_set.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanna/Documents/algorithm/fixed_set/main.cpp > CMakeFiles/fixed_set.dir/main.cpp.i

CMakeFiles/fixed_set.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fixed_set.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanna/Documents/algorithm/fixed_set/main.cpp -o CMakeFiles/fixed_set.dir/main.cpp.s

CMakeFiles/fixed_set.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/fixed_set.dir/main.cpp.o.requires

CMakeFiles/fixed_set.dir/main.cpp.o.provides: CMakeFiles/fixed_set.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fixed_set.dir/build.make CMakeFiles/fixed_set.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/fixed_set.dir/main.cpp.o.provides

CMakeFiles/fixed_set.dir/main.cpp.o.provides.build: CMakeFiles/fixed_set.dir/main.cpp.o


# Object files for target fixed_set
fixed_set_OBJECTS = \
"CMakeFiles/fixed_set.dir/main.cpp.o"

# External object files for target fixed_set
fixed_set_EXTERNAL_OBJECTS =

fixed_set: CMakeFiles/fixed_set.dir/main.cpp.o
fixed_set: CMakeFiles/fixed_set.dir/build.make
fixed_set: CMakeFiles/fixed_set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hanna/Documents/algorithm/fixed_set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fixed_set"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fixed_set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fixed_set.dir/build: fixed_set

.PHONY : CMakeFiles/fixed_set.dir/build

CMakeFiles/fixed_set.dir/requires: CMakeFiles/fixed_set.dir/main.cpp.o.requires

.PHONY : CMakeFiles/fixed_set.dir/requires

CMakeFiles/fixed_set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fixed_set.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fixed_set.dir/clean

CMakeFiles/fixed_set.dir/depend:
	cd /home/hanna/Documents/algorithm/fixed_set/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanna/Documents/algorithm/fixed_set /home/hanna/Documents/algorithm/fixed_set /home/hanna/Documents/algorithm/fixed_set/cmake-build-debug /home/hanna/Documents/algorithm/fixed_set/cmake-build-debug /home/hanna/Documents/algorithm/fixed_set/cmake-build-debug/CMakeFiles/fixed_set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fixed_set.dir/depend

