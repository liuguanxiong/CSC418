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
CMAKE_SOURCE_DIR = /Users/guanxiongliu/Desktop/CSC418/a4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/guanxiongliu/Desktop/CSC418/a4/build_release

# Include any dependencies generated for this target.
include CMakeFiles/rays.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rays.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rays.dir/flags.make

CMakeFiles/rays.dir/rays.cpp.o: CMakeFiles/rays.dir/flags.make
CMakeFiles/rays.dir/rays.cpp.o: ../rays.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/guanxiongliu/Desktop/CSC418/a4/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rays.dir/rays.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rays.dir/rays.cpp.o -c /Users/guanxiongliu/Desktop/CSC418/a4/rays.cpp

CMakeFiles/rays.dir/rays.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rays.dir/rays.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/guanxiongliu/Desktop/CSC418/a4/rays.cpp > CMakeFiles/rays.dir/rays.cpp.i

CMakeFiles/rays.dir/rays.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rays.dir/rays.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/guanxiongliu/Desktop/CSC418/a4/rays.cpp -o CMakeFiles/rays.dir/rays.cpp.s

# Object files for target rays
rays_OBJECTS = \
"CMakeFiles/rays.dir/rays.cpp.o"

# External object files for target rays
rays_EXTERNAL_OBJECTS =

rays: CMakeFiles/rays.dir/rays.cpp.o
rays: CMakeFiles/rays.dir/build.make
rays: libcore.a
rays: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
rays: glad/libglad.a
rays: glfw/src/libglfw3.a
rays: CMakeFiles/rays.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/guanxiongliu/Desktop/CSC418/a4/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rays"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rays.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rays.dir/build: rays

.PHONY : CMakeFiles/rays.dir/build

CMakeFiles/rays.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rays.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rays.dir/clean

CMakeFiles/rays.dir/depend:
	cd /Users/guanxiongliu/Desktop/CSC418/a4/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/guanxiongliu/Desktop/CSC418/a4 /Users/guanxiongliu/Desktop/CSC418/a4 /Users/guanxiongliu/Desktop/CSC418/a4/build_release /Users/guanxiongliu/Desktop/CSC418/a4/build_release /Users/guanxiongliu/Desktop/CSC418/a4/build_release/CMakeFiles/rays.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rays.dir/depend

