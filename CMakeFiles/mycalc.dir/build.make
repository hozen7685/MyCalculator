# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cmake-3.31.0-rc2-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.31.0-rc2-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hz\Downloads\MyCalculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hz\Downloads\MyCalculator

# Include any dependencies generated for this target.
include CMakeFiles/mycalc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mycalc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mycalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mycalc.dir/flags.make

CMakeFiles/mycalc.dir/codegen:
.PHONY : CMakeFiles/mycalc.dir/codegen

CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj: CMakeFiles/mycalc.dir/flags.make
CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj: CMakeFiles/mycalc.dir/includes_CXX.rsp
CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj: src/calc_backend/calculator.cpp
CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj: CMakeFiles/mycalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\hz\Downloads\MyCalculator\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj -MF CMakeFiles\mycalc.dir\src\calc_backend\calculator.cpp.obj.d -o CMakeFiles\mycalc.dir\src\calc_backend\calculator.cpp.obj -c C:\Users\hz\Downloads\MyCalculator\src\calc_backend\calculator.cpp

CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.i"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hz\Downloads\MyCalculator\src\calc_backend\calculator.cpp > CMakeFiles\mycalc.dir\src\calc_backend\calculator.cpp.i

CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.s"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hz\Downloads\MyCalculator\src\calc_backend\calculator.cpp -o CMakeFiles\mycalc.dir\src\calc_backend\calculator.cpp.s

CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj: CMakeFiles/mycalc.dir/flags.make
CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj: CMakeFiles/mycalc.dir/includes_CXX.rsp
CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj: src/calc_window/main_window.cpp
CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj: CMakeFiles/mycalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\hz\Downloads\MyCalculator\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj -MF CMakeFiles\mycalc.dir\src\calc_window\main_window.cpp.obj.d -o CMakeFiles\mycalc.dir\src\calc_window\main_window.cpp.obj -c C:\Users\hz\Downloads\MyCalculator\src\calc_window\main_window.cpp

CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.i"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hz\Downloads\MyCalculator\src\calc_window\main_window.cpp > CMakeFiles\mycalc.dir\src\calc_window\main_window.cpp.i

CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.s"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hz\Downloads\MyCalculator\src\calc_window\main_window.cpp -o CMakeFiles\mycalc.dir\src\calc_window\main_window.cpp.s

CMakeFiles/mycalc.dir/src/main.cpp.obj: CMakeFiles/mycalc.dir/flags.make
CMakeFiles/mycalc.dir/src/main.cpp.obj: CMakeFiles/mycalc.dir/includes_CXX.rsp
CMakeFiles/mycalc.dir/src/main.cpp.obj: src/main.cpp
CMakeFiles/mycalc.dir/src/main.cpp.obj: CMakeFiles/mycalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\hz\Downloads\MyCalculator\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mycalc.dir/src/main.cpp.obj"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mycalc.dir/src/main.cpp.obj -MF CMakeFiles\mycalc.dir\src\main.cpp.obj.d -o CMakeFiles\mycalc.dir\src\main.cpp.obj -c C:\Users\hz\Downloads\MyCalculator\src\main.cpp

CMakeFiles/mycalc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mycalc.dir/src/main.cpp.i"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hz\Downloads\MyCalculator\src\main.cpp > CMakeFiles\mycalc.dir\src\main.cpp.i

CMakeFiles/mycalc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mycalc.dir/src/main.cpp.s"
	c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hz\Downloads\MyCalculator\src\main.cpp -o CMakeFiles\mycalc.dir\src\main.cpp.s

# Object files for target mycalc
mycalc_OBJECTS = \
"CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj" \
"CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj" \
"CMakeFiles/mycalc.dir/src/main.cpp.obj"

# External object files for target mycalc
mycalc_EXTERNAL_OBJECTS =

mycalc.exe: CMakeFiles/mycalc.dir/src/calc_backend/calculator.cpp.obj
mycalc.exe: CMakeFiles/mycalc.dir/src/calc_window/main_window.cpp.obj
mycalc.exe: CMakeFiles/mycalc.dir/src/main.cpp.obj
mycalc.exe: CMakeFiles/mycalc.dir/build.make
mycalc.exe: CMakeFiles/mycalc.dir/linkLibs.rsp
mycalc.exe: CMakeFiles/mycalc.dir/objects1.rsp
mycalc.exe: CMakeFiles/mycalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\hz\Downloads\MyCalculator\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mycalc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mycalc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mycalc.dir/build: mycalc.exe
.PHONY : CMakeFiles/mycalc.dir/build

CMakeFiles/mycalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mycalc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mycalc.dir/clean

CMakeFiles/mycalc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hz\Downloads\MyCalculator C:\Users\hz\Downloads\MyCalculator C:\Users\hz\Downloads\MyCalculator C:\Users\hz\Downloads\MyCalculator C:\Users\hz\Downloads\MyCalculator\CMakeFiles\mycalc.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mycalc.dir/depend

