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
include CMakeFiles/ql.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ql.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ql.dir/flags.make

CMakeFiles/ql.dir/src/ql_error.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_error.cc.o: src/ql_error.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ql.dir/src/ql_error.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_error.cc.o -c /home/ubuntu/redbase/src/ql_error.cc

CMakeFiles/ql.dir/src/ql_error.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_error.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_error.cc > CMakeFiles/ql.dir/src/ql_error.cc.i

CMakeFiles/ql.dir/src/ql_error.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_error.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_error.cc -o CMakeFiles/ql.dir/src/ql_error.cc.s

CMakeFiles/ql.dir/src/ql_error.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_error.cc.o.requires

CMakeFiles/ql.dir/src/ql_error.cc.o.provides: CMakeFiles/ql.dir/src/ql_error.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_error.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_error.cc.o.provides

CMakeFiles/ql.dir/src/ql_error.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_error.cc.o


CMakeFiles/ql.dir/src/ql_manager.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_manager.cc.o: src/ql_manager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ql.dir/src/ql_manager.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_manager.cc.o -c /home/ubuntu/redbase/src/ql_manager.cc

CMakeFiles/ql.dir/src/ql_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_manager.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_manager.cc > CMakeFiles/ql.dir/src/ql_manager.cc.i

CMakeFiles/ql.dir/src/ql_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_manager.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_manager.cc -o CMakeFiles/ql.dir/src/ql_manager.cc.s

CMakeFiles/ql.dir/src/ql_manager.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_manager.cc.o.requires

CMakeFiles/ql.dir/src/ql_manager.cc.o.provides: CMakeFiles/ql.dir/src/ql_manager.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_manager.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_manager.cc.o.provides

CMakeFiles/ql.dir/src/ql_manager.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_manager.cc.o


CMakeFiles/ql.dir/src/ql_node.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_node.cc.o: src/ql_node.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ql.dir/src/ql_node.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_node.cc.o -c /home/ubuntu/redbase/src/ql_node.cc

CMakeFiles/ql.dir/src/ql_node.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_node.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_node.cc > CMakeFiles/ql.dir/src/ql_node.cc.i

CMakeFiles/ql.dir/src/ql_node.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_node.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_node.cc -o CMakeFiles/ql.dir/src/ql_node.cc.s

CMakeFiles/ql.dir/src/ql_node.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_node.cc.o.requires

CMakeFiles/ql.dir/src/ql_node.cc.o.provides: CMakeFiles/ql.dir/src/ql_node.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_node.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_node.cc.o.provides

CMakeFiles/ql.dir/src/ql_node.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_node.cc.o


CMakeFiles/ql.dir/src/ql_nodeproj.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_nodeproj.cc.o: src/ql_nodeproj.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ql.dir/src/ql_nodeproj.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_nodeproj.cc.o -c /home/ubuntu/redbase/src/ql_nodeproj.cc

CMakeFiles/ql.dir/src/ql_nodeproj.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_nodeproj.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_nodeproj.cc > CMakeFiles/ql.dir/src/ql_nodeproj.cc.i

CMakeFiles/ql.dir/src/ql_nodeproj.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_nodeproj.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_nodeproj.cc -o CMakeFiles/ql.dir/src/ql_nodeproj.cc.s

CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.requires

CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.provides: CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.provides

CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_nodeproj.cc.o


CMakeFiles/ql.dir/src/ql_noderel.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_noderel.cc.o: src/ql_noderel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ql.dir/src/ql_noderel.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_noderel.cc.o -c /home/ubuntu/redbase/src/ql_noderel.cc

CMakeFiles/ql.dir/src/ql_noderel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_noderel.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_noderel.cc > CMakeFiles/ql.dir/src/ql_noderel.cc.i

CMakeFiles/ql.dir/src/ql_noderel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_noderel.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_noderel.cc -o CMakeFiles/ql.dir/src/ql_noderel.cc.s

CMakeFiles/ql.dir/src/ql_noderel.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_noderel.cc.o.requires

CMakeFiles/ql.dir/src/ql_noderel.cc.o.provides: CMakeFiles/ql.dir/src/ql_noderel.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_noderel.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_noderel.cc.o.provides

CMakeFiles/ql.dir/src/ql_noderel.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_noderel.cc.o


CMakeFiles/ql.dir/src/ql_nodejoin.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_nodejoin.cc.o: src/ql_nodejoin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ql.dir/src/ql_nodejoin.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_nodejoin.cc.o -c /home/ubuntu/redbase/src/ql_nodejoin.cc

CMakeFiles/ql.dir/src/ql_nodejoin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_nodejoin.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_nodejoin.cc > CMakeFiles/ql.dir/src/ql_nodejoin.cc.i

CMakeFiles/ql.dir/src/ql_nodejoin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_nodejoin.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_nodejoin.cc -o CMakeFiles/ql.dir/src/ql_nodejoin.cc.s

CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.requires

CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.provides: CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.provides

CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_nodejoin.cc.o


CMakeFiles/ql.dir/src/ql_nodesel.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/ql_nodesel.cc.o: src/ql_nodesel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ql.dir/src/ql_nodesel.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/ql_nodesel.cc.o -c /home/ubuntu/redbase/src/ql_nodesel.cc

CMakeFiles/ql.dir/src/ql_nodesel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/ql_nodesel.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/ql_nodesel.cc > CMakeFiles/ql.dir/src/ql_nodesel.cc.i

CMakeFiles/ql.dir/src/ql_nodesel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/ql_nodesel.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/ql_nodesel.cc -o CMakeFiles/ql.dir/src/ql_nodesel.cc.s

CMakeFiles/ql.dir/src/ql_nodesel.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/ql_nodesel.cc.o.requires

CMakeFiles/ql.dir/src/ql_nodesel.cc.o.provides: CMakeFiles/ql.dir/src/ql_nodesel.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/ql_nodesel.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/ql_nodesel.cc.o.provides

CMakeFiles/ql.dir/src/ql_nodesel.cc.o.provides.build: CMakeFiles/ql.dir/src/ql_nodesel.cc.o


CMakeFiles/ql.dir/src/qo_manager.cc.o: CMakeFiles/ql.dir/flags.make
CMakeFiles/ql.dir/src/qo_manager.cc.o: src/qo_manager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ql.dir/src/qo_manager.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ql.dir/src/qo_manager.cc.o -c /home/ubuntu/redbase/src/qo_manager.cc

CMakeFiles/ql.dir/src/qo_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ql.dir/src/qo_manager.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/qo_manager.cc > CMakeFiles/ql.dir/src/qo_manager.cc.i

CMakeFiles/ql.dir/src/qo_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ql.dir/src/qo_manager.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/qo_manager.cc -o CMakeFiles/ql.dir/src/qo_manager.cc.s

CMakeFiles/ql.dir/src/qo_manager.cc.o.requires:

.PHONY : CMakeFiles/ql.dir/src/qo_manager.cc.o.requires

CMakeFiles/ql.dir/src/qo_manager.cc.o.provides: CMakeFiles/ql.dir/src/qo_manager.cc.o.requires
	$(MAKE) -f CMakeFiles/ql.dir/build.make CMakeFiles/ql.dir/src/qo_manager.cc.o.provides.build
.PHONY : CMakeFiles/ql.dir/src/qo_manager.cc.o.provides

CMakeFiles/ql.dir/src/qo_manager.cc.o.provides.build: CMakeFiles/ql.dir/src/qo_manager.cc.o


# Object files for target ql
ql_OBJECTS = \
"CMakeFiles/ql.dir/src/ql_error.cc.o" \
"CMakeFiles/ql.dir/src/ql_manager.cc.o" \
"CMakeFiles/ql.dir/src/ql_node.cc.o" \
"CMakeFiles/ql.dir/src/ql_nodeproj.cc.o" \
"CMakeFiles/ql.dir/src/ql_noderel.cc.o" \
"CMakeFiles/ql.dir/src/ql_nodejoin.cc.o" \
"CMakeFiles/ql.dir/src/ql_nodesel.cc.o" \
"CMakeFiles/ql.dir/src/qo_manager.cc.o"

# External object files for target ql
ql_EXTERNAL_OBJECTS =

libql.a: CMakeFiles/ql.dir/src/ql_error.cc.o
libql.a: CMakeFiles/ql.dir/src/ql_manager.cc.o
libql.a: CMakeFiles/ql.dir/src/ql_node.cc.o
libql.a: CMakeFiles/ql.dir/src/ql_nodeproj.cc.o
libql.a: CMakeFiles/ql.dir/src/ql_noderel.cc.o
libql.a: CMakeFiles/ql.dir/src/ql_nodejoin.cc.o
libql.a: CMakeFiles/ql.dir/src/ql_nodesel.cc.o
libql.a: CMakeFiles/ql.dir/src/qo_manager.cc.o
libql.a: CMakeFiles/ql.dir/build.make
libql.a: CMakeFiles/ql.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library libql.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ql.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ql.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ql.dir/build: libql.a

.PHONY : CMakeFiles/ql.dir/build

CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_error.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_manager.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_node.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_nodeproj.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_noderel.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_nodejoin.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/ql_nodesel.cc.o.requires
CMakeFiles/ql.dir/requires: CMakeFiles/ql.dir/src/qo_manager.cc.o.requires

.PHONY : CMakeFiles/ql.dir/requires

CMakeFiles/ql.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ql.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ql.dir/clean

CMakeFiles/ql.dir/depend:
	cd /home/ubuntu/redbase && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase/CMakeFiles/ql.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ql.dir/depend

