# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/guanxiongliu/Desktop/CSC418/a5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/guanxiongliu/Desktop/CSC418/a5/build_release

# Include any dependencies generated for this target.
include CMakeFiles/normals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/normals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/normals.dir/flags.make

CMakeFiles/normals.dir/normals.cpp.o: CMakeFiles/normals.dir/flags.make
CMakeFiles/normals.dir/normals.cpp.o: ../normals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/guanxiongliu/Desktop/CSC418/a5/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/normals.dir/normals.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/normals.dir/normals.cpp.o -c /Users/guanxiongliu/Desktop/CSC418/a5/normals.cpp

CMakeFiles/normals.dir/normals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/normals.dir/normals.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/guanxiongliu/Desktop/CSC418/a5/normals.cpp > CMakeFiles/normals.dir/normals.cpp.i

CMakeFiles/normals.dir/normals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/normals.dir/normals.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/guanxiongliu/Desktop/CSC418/a5/normals.cpp -o CMakeFiles/normals.dir/normals.cpp.s

# Object files for target normals
normals_OBJECTS = \
"CMakeFiles/normals.dir/normals.cpp.o"

# External object files for target normals
normals_EXTERNAL_OBJECTS =

normals: CMakeFiles/normals.dir/normals.cpp.o
normals: CMakeFiles/normals.dir/build.make
normals: libcore.a
normals: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
normals: glad/libglad.a
normals: glfw/src/libglfw3.a
normals: CMakeFiles/normals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/guanxiongliu/Desktop/CSC418/a5/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable normals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/normals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/normals.dir/build: normals

.PHONY : CMakeFiles/normals.dir/build

CMakeFiles/normals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/normals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/normals.dir/clean

CMakeFiles/normals.dir/depend:
	cd /Users/guanxiongliu/Desktop/CSC418/a5/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/guanxiongliu/Desktop/CSC418/a5 /Users/guanxiongliu/Desktop/CSC418/a5 /Users/guanxiongliu/Desktop/CSC418/a5/build_release /Users/guanxiongliu/Desktop/CSC418/a5/build_release /Users/guanxiongliu/Desktop/CSC418/a5/build_release/CMakeFiles/normals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/normals.dir/depend

