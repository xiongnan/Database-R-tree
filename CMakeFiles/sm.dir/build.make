# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/redbase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/redbase

# Include any dependencies generated for this target.
include CMakeFiles/sm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sm.dir/flags.make

CMakeFiles/sm.dir/src/sm_manager.cc.o: CMakeFiles/sm.dir/flags.make
CMakeFiles/sm.dir/src/sm_manager.cc.o: src/sm_manager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sm.dir/src/sm_manager.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sm.dir/src/sm_manager.cc.o -c /home/ubuntu/redbase/src/sm_manager.cc

CMakeFiles/sm.dir/src/sm_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sm.dir/src/sm_manager.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/sm_manager.cc > CMakeFiles/sm.dir/src/sm_manager.cc.i

CMakeFiles/sm.dir/src/sm_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sm.dir/src/sm_manager.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/sm_manager.cc -o CMakeFiles/sm.dir/src/sm_manager.cc.s

CMakeFiles/sm.dir/src/sm_manager.cc.o.requires:

.PHONY : CMakeFiles/sm.dir/src/sm_manager.cc.o.requires

CMakeFiles/sm.dir/src/sm_manager.cc.o.provides: CMakeFiles/sm.dir/src/sm_manager.cc.o.requires
	$(MAKE) -f CMakeFiles/sm.dir/build.make CMakeFiles/sm.dir/src/sm_manager.cc.o.provides.build
.PHONY : CMakeFiles/sm.dir/src/sm_manager.cc.o.provides

CMakeFiles/sm.dir/src/sm_manager.cc.o.provides.build: CMakeFiles/sm.dir/src/sm_manager.cc.o


CMakeFiles/sm.dir/src/printer.cc.o: CMakeFiles/sm.dir/flags.make
CMakeFiles/sm.dir/src/printer.cc.o: src/printer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sm.dir/src/printer.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sm.dir/src/printer.cc.o -c /home/ubuntu/redbase/src/printer.cc

CMakeFiles/sm.dir/src/printer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sm.dir/src/printer.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/printer.cc > CMakeFiles/sm.dir/src/printer.cc.i

CMakeFiles/sm.dir/src/printer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sm.dir/src/printer.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/printer.cc -o CMakeFiles/sm.dir/src/printer.cc.s

CMakeFiles/sm.dir/src/printer.cc.o.requires:

.PHONY : CMakeFiles/sm.dir/src/printer.cc.o.requires

CMakeFiles/sm.dir/src/printer.cc.o.provides: CMakeFiles/sm.dir/src/printer.cc.o.requires
	$(MAKE) -f CMakeFiles/sm.dir/build.make CMakeFiles/sm.dir/src/printer.cc.o.provides.build
.PHONY : CMakeFiles/sm.dir/src/printer.cc.o.provides

CMakeFiles/sm.dir/src/printer.cc.o.provides.build: CMakeFiles/sm.dir/src/printer.cc.o


CMakeFiles/sm.dir/src/sm_error.cc.o: CMakeFiles/sm.dir/flags.make
CMakeFiles/sm.dir/src/sm_error.cc.o: src/sm_error.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sm.dir/src/sm_error.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sm.dir/src/sm_error.cc.o -c /home/ubuntu/redbase/src/sm_error.cc

CMakeFiles/sm.dir/src/sm_error.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sm.dir/src/sm_error.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/sm_error.cc > CMakeFiles/sm.dir/src/sm_error.cc.i

CMakeFiles/sm.dir/src/sm_error.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sm.dir/src/sm_error.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/sm_error.cc -o CMakeFiles/sm.dir/src/sm_error.cc.s

CMakeFiles/sm.dir/src/sm_error.cc.o.requires:

.PHONY : CMakeFiles/sm.dir/src/sm_error.cc.o.requires

CMakeFiles/sm.dir/src/sm_error.cc.o.provides: CMakeFiles/sm.dir/src/sm_error.cc.o.requires
	$(MAKE) -f CMakeFiles/sm.dir/build.make CMakeFiles/sm.dir/src/sm_error.cc.o.provides.build
.PHONY : CMakeFiles/sm.dir/src/sm_error.cc.o.provides

CMakeFiles/sm.dir/src/sm_error.cc.o.provides.build: CMakeFiles/sm.dir/src/sm_error.cc.o


CMakeFiles/sm.dir/src/sm_attriterator.cc.o: CMakeFiles/sm.dir/flags.make
CMakeFiles/sm.dir/src/sm_attriterator.cc.o: src/sm_attriterator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sm.dir/src/sm_attriterator.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sm.dir/src/sm_attriterator.cc.o -c /home/ubuntu/redbase/src/sm_attriterator.cc

CMakeFiles/sm.dir/src/sm_attriterator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sm.dir/src/sm_attriterator.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/sm_attriterator.cc > CMakeFiles/sm.dir/src/sm_attriterator.cc.i

CMakeFiles/sm.dir/src/sm_attriterator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sm.dir/src/sm_attriterator.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/sm_attriterator.cc -o CMakeFiles/sm.dir/src/sm_attriterator.cc.s

CMakeFiles/sm.dir/src/sm_attriterator.cc.o.requires:

.PHONY : CMakeFiles/sm.dir/src/sm_attriterator.cc.o.requires

CMakeFiles/sm.dir/src/sm_attriterator.cc.o.provides: CMakeFiles/sm.dir/src/sm_attriterator.cc.o.requires
	$(MAKE) -f CMakeFiles/sm.dir/build.make CMakeFiles/sm.dir/src/sm_attriterator.cc.o.provides.build
.PHONY : CMakeFiles/sm.dir/src/sm_attriterator.cc.o.provides

CMakeFiles/sm.dir/src/sm_attriterator.cc.o.provides.build: CMakeFiles/sm.dir/src/sm_attriterator.cc.o


# Object files for target sm
sm_OBJECTS = \
"CMakeFiles/sm.dir/src/sm_manager.cc.o" \
"CMakeFiles/sm.dir/src/printer.cc.o" \
"CMakeFiles/sm.dir/src/sm_error.cc.o" \
"CMakeFiles/sm.dir/src/sm_attriterator.cc.o"

# External object files for target sm
sm_EXTERNAL_OBJECTS =

libsm.a: CMakeFiles/sm.dir/src/sm_manager.cc.o
libsm.a: CMakeFiles/sm.dir/src/printer.cc.o
libsm.a: CMakeFiles/sm.dir/src/sm_error.cc.o
libsm.a: CMakeFiles/sm.dir/src/sm_attriterator.cc.o
libsm.a: CMakeFiles/sm.dir/build.make
libsm.a: CMakeFiles/sm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libsm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sm.dir/build: libsm.a

.PHONY : CMakeFiles/sm.dir/build

CMakeFiles/sm.dir/requires: CMakeFiles/sm.dir/src/sm_manager.cc.o.requires
CMakeFiles/sm.dir/requires: CMakeFiles/sm.dir/src/printer.cc.o.requires
CMakeFiles/sm.dir/requires: CMakeFiles/sm.dir/src/sm_error.cc.o.requires
CMakeFiles/sm.dir/requires: CMakeFiles/sm.dir/src/sm_attriterator.cc.o.requires

.PHONY : CMakeFiles/sm.dir/requires

CMakeFiles/sm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sm.dir/clean

CMakeFiles/sm.dir/depend:
	cd /home/ubuntu/redbase && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase/CMakeFiles/sm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sm.dir/depend

