# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/teste

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug

# Utility rule file for teste_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/teste_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/teste_autogen.dir/progress.make

CMakeFiles/teste_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target teste"
	/usr/bin/cmake -E cmake_autogen /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug/CMakeFiles/teste_autogen.dir/AutogenInfo.json Debug

teste_autogen: CMakeFiles/teste_autogen
teste_autogen: CMakeFiles/teste_autogen.dir/build.make
.PHONY : teste_autogen

# Rule to build all files generated by this target.
CMakeFiles/teste_autogen.dir/build: teste_autogen
.PHONY : CMakeFiles/teste_autogen.dir/build

CMakeFiles/teste_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/teste_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/teste_autogen.dir/clean

CMakeFiles/teste_autogen.dir/depend:
	cd /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/teste /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/teste /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug /home/jorgeschuastz/treinamento/ATV1/jorge-schuastz/qt_new/cpp-libiry/helloLib/hello/build-teste-Desktop_b33181-Debug/CMakeFiles/teste_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/teste_autogen.dir/depend

