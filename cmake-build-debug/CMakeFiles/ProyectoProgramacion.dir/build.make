# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ProyectoProgramacion.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProyectoProgramacion.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProyectoProgramacion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProyectoProgramacion.dir/flags.make

CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj: CMakeFiles/ProyectoProgramacion.dir/flags.make
CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj: C:/Users/Admin/Documents/Projects/C\ plus\ plus/Proyecto-I-Programaci-n-/main.cpp
CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj: CMakeFiles/ProyectoProgramacion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj -MF CMakeFiles\ProyectoProgramacion.dir\main.cpp.obj.d -o CMakeFiles\ProyectoProgramacion.dir\main.cpp.obj -c "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\main.cpp"

CMakeFiles/ProyectoProgramacion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgramacion.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\main.cpp" > CMakeFiles\ProyectoProgramacion.dir\main.cpp.i

CMakeFiles/ProyectoProgramacion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgramacion.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\main.cpp" -o CMakeFiles\ProyectoProgramacion.dir\main.cpp.s

# Object files for target ProyectoProgramacion
ProyectoProgramacion_OBJECTS = \
"CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj"

# External object files for target ProyectoProgramacion
ProyectoProgramacion_EXTERNAL_OBJECTS =

ProyectoProgramacion.exe: CMakeFiles/ProyectoProgramacion.dir/main.cpp.obj
ProyectoProgramacion.exe: CMakeFiles/ProyectoProgramacion.dir/build.make
ProyectoProgramacion.exe: CMakeFiles/ProyectoProgramacion.dir/linkLibs.rsp
ProyectoProgramacion.exe: CMakeFiles/ProyectoProgramacion.dir/objects1.rsp
ProyectoProgramacion.exe: CMakeFiles/ProyectoProgramacion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProyectoProgramacion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProyectoProgramacion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProyectoProgramacion.dir/build: ProyectoProgramacion.exe
.PHONY : CMakeFiles/ProyectoProgramacion.dir/build

CMakeFiles/ProyectoProgramacion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProyectoProgramacion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProyectoProgramacion.dir/clean

CMakeFiles/ProyectoProgramacion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-" "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-" "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\cmake-build-debug" "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\cmake-build-debug" "C:\Users\Admin\Documents\Projects\C plus plus\Proyecto-I-Programaci-n-\cmake-build-debug\CMakeFiles\ProyectoProgramacion.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/ProyectoProgramacion.dir/depend

