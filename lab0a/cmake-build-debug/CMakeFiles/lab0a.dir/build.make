# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\cpp\lab0a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\cpp\lab0a\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab0a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab0a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab0a.dir/flags.make

CMakeFiles/lab0a.dir/main.cpp.obj: CMakeFiles/lab0a.dir/flags.make
CMakeFiles/lab0a.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\cpp\lab0a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab0a.dir/main.cpp.obj"
	D:\MInGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab0a.dir\main.cpp.obj -c D:\cpp\lab0a\main.cpp

CMakeFiles/lab0a.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab0a.dir/main.cpp.i"
	D:\MInGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\lab0a\main.cpp > CMakeFiles\lab0a.dir\main.cpp.i

CMakeFiles/lab0a.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab0a.dir/main.cpp.s"
	D:\MInGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\lab0a\main.cpp -o CMakeFiles\lab0a.dir\main.cpp.s

CMakeFiles/lab0a.dir/module1.cpp.obj: CMakeFiles/lab0a.dir/flags.make
CMakeFiles/lab0a.dir/module1.cpp.obj: ../module1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\cpp\lab0a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab0a.dir/module1.cpp.obj"
	D:\MInGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab0a.dir\module1.cpp.obj -c D:\cpp\lab0a\module1.cpp

CMakeFiles/lab0a.dir/module1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab0a.dir/module1.cpp.i"
	D:\MInGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\lab0a\module1.cpp > CMakeFiles\lab0a.dir\module1.cpp.i

CMakeFiles/lab0a.dir/module1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab0a.dir/module1.cpp.s"
	D:\MInGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\lab0a\module1.cpp -o CMakeFiles\lab0a.dir\module1.cpp.s

CMakeFiles/lab0a.dir/module2.cpp.obj: CMakeFiles/lab0a.dir/flags.make
CMakeFiles/lab0a.dir/module2.cpp.obj: ../module2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\cpp\lab0a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab0a.dir/module2.cpp.obj"
	D:\MInGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab0a.dir\module2.cpp.obj -c D:\cpp\lab0a\module2.cpp

CMakeFiles/lab0a.dir/module2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab0a.dir/module2.cpp.i"
	D:\MInGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\lab0a\module2.cpp > CMakeFiles\lab0a.dir\module2.cpp.i

CMakeFiles/lab0a.dir/module2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab0a.dir/module2.cpp.s"
	D:\MInGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\lab0a\module2.cpp -o CMakeFiles\lab0a.dir\module2.cpp.s

# Object files for target lab0a
lab0a_OBJECTS = \
"CMakeFiles/lab0a.dir/main.cpp.obj" \
"CMakeFiles/lab0a.dir/module1.cpp.obj" \
"CMakeFiles/lab0a.dir/module2.cpp.obj"

# External object files for target lab0a
lab0a_EXTERNAL_OBJECTS =

lab0a.exe: CMakeFiles/lab0a.dir/main.cpp.obj
lab0a.exe: CMakeFiles/lab0a.dir/module1.cpp.obj
lab0a.exe: CMakeFiles/lab0a.dir/module2.cpp.obj
lab0a.exe: CMakeFiles/lab0a.dir/build.make
lab0a.exe: CMakeFiles/lab0a.dir/linklibs.rsp
lab0a.exe: CMakeFiles/lab0a.dir/objects1.rsp
lab0a.exe: CMakeFiles/lab0a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\cpp\lab0a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lab0a.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab0a.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab0a.dir/build: lab0a.exe

.PHONY : CMakeFiles/lab0a.dir/build

CMakeFiles/lab0a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab0a.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab0a.dir/clean

CMakeFiles/lab0a.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\cpp\lab0a D:\cpp\lab0a D:\cpp\lab0a\cmake-build-debug D:\cpp\lab0a\cmake-build-debug D:\cpp\lab0a\cmake-build-debug\CMakeFiles\lab0a.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab0a.dir/depend

