# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guanxiong/Desktop/CSC418/a5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guanxiong/Desktop/CSC418/a5/build_release

# Include any dependencies generated for this target.
include CMakeFiles/normals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/normals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/normals.dir/flags.make

CMakeFiles/normals.dir/normals.cpp.o: CMakeFiles/normals.dir/flags.make
CMakeFiles/normals.dir/normals.cpp.o: ../normals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guanxiong/Desktop/CSC418/a5/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/normals.dir/normals.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/normals.dir/normals.cpp.o -c /home/guanxiong/Desktop/CSC418/a5/normals.cpp

CMakeFiles/normals.dir/normals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/normals.dir/normals.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guanxiong/Desktop/CSC418/a5/normals.cpp > CMakeFiles/normals.dir/normals.cpp.i

CMakeFiles/normals.dir/normals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/normals.dir/normals.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guanxiong/Desktop/CSC418/a5/normals.cpp -o CMakeFiles/normals.dir/normals.cpp.s

CMakeFiles/normals.dir/normals.cpp.o.requires:

.PHONY : CMakeFiles/normals.dir/normals.cpp.o.requires

CMakeFiles/normals.dir/normals.cpp.o.provides: CMakeFiles/normals.dir/normals.cpp.o.requires
	$(MAKE) -f CMakeFiles/normals.dir/build.make CMakeFiles/normals.dir/normals.cpp.o.provides.build
.PHONY : CMakeFiles/normals.dir/normals.cpp.o.provides

CMakeFiles/normals.dir/normals.cpp.o.provides.build: CMakeFiles/normals.dir/normals.cpp.o


# Object files for target normals
normals_OBJECTS = \
"CMakeFiles/normals.dir/normals.cpp.o"

# External object files for target normals
normals_EXTERNAL_OBJECTS =

normals: CMakeFiles/normals.dir/normals.cpp.o
normals: CMakeFiles/normals.dir/build.make
normals: libcore.a
normals: /usr/lib/x86_64-linux-gnu/libGL.so
normals: glad/libglad.a
normals: glfw/src/libglfw3.a
normals: /usr/lib/x86_64-linux-gnu/librt.so
normals: /usr/lib/x86_64-linux-gnu/libm.so
normals: /usr/lib/x86_64-linux-gnu/libX11.so
normals: CMakeFiles/normals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guanxiong/Desktop/CSC418/a5/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable normals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/normals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/normals.dir/build: normals

.PHONY : CMakeFiles/normals.dir/build

CMakeFiles/normals.dir/requires: CMakeFiles/normals.dir/normals.cpp.o.requires

.PHONY : CMakeFiles/normals.dir/requires

CMakeFiles/normals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/normals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/normals.dir/clean

CMakeFiles/normals.dir/depend:
	cd /home/guanxiong/Desktop/CSC418/a5/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guanxiong/Desktop/CSC418/a5 /home/guanxiong/Desktop/CSC418/a5 /home/guanxiong/Desktop/CSC418/a5/build_release /home/guanxiong/Desktop/CSC418/a5/build_release /home/guanxiong/Desktop/CSC418/a5/build_release/CMakeFiles/normals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/normals.dir/depend

