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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sunwanqi/Documents/yuanfudao_oneMore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/oneMore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/oneMore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oneMore.dir/flags.make

CMakeFiles/oneMore.dir/main.cpp.o: CMakeFiles/oneMore.dir/flags.make
CMakeFiles/oneMore.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oneMore.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oneMore.dir/main.cpp.o -c /Users/sunwanqi/Documents/yuanfudao_oneMore/main.cpp

CMakeFiles/oneMore.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oneMore.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sunwanqi/Documents/yuanfudao_oneMore/main.cpp > CMakeFiles/oneMore.dir/main.cpp.i

CMakeFiles/oneMore.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oneMore.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sunwanqi/Documents/yuanfudao_oneMore/main.cpp -o CMakeFiles/oneMore.dir/main.cpp.s

CMakeFiles/oneMore.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/oneMore.dir/main.cpp.o.requires

CMakeFiles/oneMore.dir/main.cpp.o.provides: CMakeFiles/oneMore.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/oneMore.dir/build.make CMakeFiles/oneMore.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/oneMore.dir/main.cpp.o.provides

CMakeFiles/oneMore.dir/main.cpp.o.provides.build: CMakeFiles/oneMore.dir/main.cpp.o


CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o: CMakeFiles/oneMore.dir/flags.make
CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o: ../oneMoreOperator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o -c /Users/sunwanqi/Documents/yuanfudao_oneMore/oneMoreOperator.cpp

CMakeFiles/oneMore.dir/oneMoreOperator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oneMore.dir/oneMoreOperator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sunwanqi/Documents/yuanfudao_oneMore/oneMoreOperator.cpp > CMakeFiles/oneMore.dir/oneMoreOperator.cpp.i

CMakeFiles/oneMore.dir/oneMoreOperator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oneMore.dir/oneMoreOperator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sunwanqi/Documents/yuanfudao_oneMore/oneMoreOperator.cpp -o CMakeFiles/oneMore.dir/oneMoreOperator.cpp.s

CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.requires:

.PHONY : CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.requires

CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.provides: CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.requires
	$(MAKE) -f CMakeFiles/oneMore.dir/build.make CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.provides.build
.PHONY : CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.provides

CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.provides.build: CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o


# Object files for target oneMore
oneMore_OBJECTS = \
"CMakeFiles/oneMore.dir/main.cpp.o" \
"CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o"

# External object files for target oneMore
oneMore_EXTERNAL_OBJECTS =

oneMore: CMakeFiles/oneMore.dir/main.cpp.o
oneMore: CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o
oneMore: CMakeFiles/oneMore.dir/build.make
oneMore: CMakeFiles/oneMore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable oneMore"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oneMore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/oneMore.dir/build: oneMore

.PHONY : CMakeFiles/oneMore.dir/build

CMakeFiles/oneMore.dir/requires: CMakeFiles/oneMore.dir/main.cpp.o.requires
CMakeFiles/oneMore.dir/requires: CMakeFiles/oneMore.dir/oneMoreOperator.cpp.o.requires

.PHONY : CMakeFiles/oneMore.dir/requires

CMakeFiles/oneMore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/oneMore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/oneMore.dir/clean

CMakeFiles/oneMore.dir/depend:
	cd /Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunwanqi/Documents/yuanfudao_oneMore /Users/sunwanqi/Documents/yuanfudao_oneMore /Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug /Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug /Users/sunwanqi/Documents/yuanfudao_oneMore/cmake-build-debug/CMakeFiles/oneMore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/oneMore.dir/depend
