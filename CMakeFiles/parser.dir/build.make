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
include CMakeFiles/parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

parse.cpp: src/parse.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][MyParser] Building parser with bison 3.0.2"
	/usr/bin/bison -d -o /home/ubuntu/redbase/parse.cpp src/parse.y

parse.hpp: parse.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parse.hpp

scan.cpp: src/scan.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][MyScanner] Building scanner with flex 2.5.35"
	/usr/bin/flex -o/home/ubuntu/redbase/scan.cpp src/scan.l

CMakeFiles/parser.dir/src/nodes.cc.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/src/nodes.cc.o: src/nodes.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/parser.dir/src/nodes.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/src/nodes.cc.o -c /home/ubuntu/redbase/src/nodes.cc

CMakeFiles/parser.dir/src/nodes.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/src/nodes.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/nodes.cc > CMakeFiles/parser.dir/src/nodes.cc.i

CMakeFiles/parser.dir/src/nodes.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/src/nodes.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/nodes.cc -o CMakeFiles/parser.dir/src/nodes.cc.s

CMakeFiles/parser.dir/src/nodes.cc.o.requires:

.PHONY : CMakeFiles/parser.dir/src/nodes.cc.o.requires

CMakeFiles/parser.dir/src/nodes.cc.o.provides: CMakeFiles/parser.dir/src/nodes.cc.o.requires
	$(MAKE) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/src/nodes.cc.o.provides.build
.PHONY : CMakeFiles/parser.dir/src/nodes.cc.o.provides

CMakeFiles/parser.dir/src/nodes.cc.o.provides.build: CMakeFiles/parser.dir/src/nodes.cc.o


CMakeFiles/parser.dir/src/interp.cc.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/src/interp.cc.o: src/interp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/parser.dir/src/interp.cc.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/src/interp.cc.o -c /home/ubuntu/redbase/src/interp.cc

CMakeFiles/parser.dir/src/interp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/src/interp.cc.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/src/interp.cc > CMakeFiles/parser.dir/src/interp.cc.i

CMakeFiles/parser.dir/src/interp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/src/interp.cc.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/src/interp.cc -o CMakeFiles/parser.dir/src/interp.cc.s

CMakeFiles/parser.dir/src/interp.cc.o.requires:

.PHONY : CMakeFiles/parser.dir/src/interp.cc.o.requires

CMakeFiles/parser.dir/src/interp.cc.o.provides: CMakeFiles/parser.dir/src/interp.cc.o.requires
	$(MAKE) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/src/interp.cc.o.provides.build
.PHONY : CMakeFiles/parser.dir/src/interp.cc.o.provides

CMakeFiles/parser.dir/src/interp.cc.o.provides.build: CMakeFiles/parser.dir/src/interp.cc.o


CMakeFiles/parser.dir/parse.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/parse.cpp.o: parse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/parser.dir/parse.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/parse.cpp.o -c /home/ubuntu/redbase/parse.cpp

CMakeFiles/parser.dir/parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/parse.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/parse.cpp > CMakeFiles/parser.dir/parse.cpp.i

CMakeFiles/parser.dir/parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/parse.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/parse.cpp -o CMakeFiles/parser.dir/parse.cpp.s

CMakeFiles/parser.dir/parse.cpp.o.requires:

.PHONY : CMakeFiles/parser.dir/parse.cpp.o.requires

CMakeFiles/parser.dir/parse.cpp.o.provides: CMakeFiles/parser.dir/parse.cpp.o.requires
	$(MAKE) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/parse.cpp.o.provides.build
.PHONY : CMakeFiles/parser.dir/parse.cpp.o.provides

CMakeFiles/parser.dir/parse.cpp.o.provides.build: CMakeFiles/parser.dir/parse.cpp.o


CMakeFiles/parser.dir/scan.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/scan.cpp.o: scan.cpp
CMakeFiles/parser.dir/scan.cpp.o: parse.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/parser.dir/scan.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/scan.cpp.o -c /home/ubuntu/redbase/scan.cpp

CMakeFiles/parser.dir/scan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/scan.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/redbase/scan.cpp > CMakeFiles/parser.dir/scan.cpp.i

CMakeFiles/parser.dir/scan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/scan.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/redbase/scan.cpp -o CMakeFiles/parser.dir/scan.cpp.s

CMakeFiles/parser.dir/scan.cpp.o.requires:

.PHONY : CMakeFiles/parser.dir/scan.cpp.o.requires

CMakeFiles/parser.dir/scan.cpp.o.provides: CMakeFiles/parser.dir/scan.cpp.o.requires
	$(MAKE) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/scan.cpp.o.provides.build
.PHONY : CMakeFiles/parser.dir/scan.cpp.o.provides

CMakeFiles/parser.dir/scan.cpp.o.provides.build: CMakeFiles/parser.dir/scan.cpp.o


# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/src/nodes.cc.o" \
"CMakeFiles/parser.dir/src/interp.cc.o" \
"CMakeFiles/parser.dir/parse.cpp.o" \
"CMakeFiles/parser.dir/scan.cpp.o"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

libparser.a: CMakeFiles/parser.dir/src/nodes.cc.o
libparser.a: CMakeFiles/parser.dir/src/interp.cc.o
libparser.a: CMakeFiles/parser.dir/parse.cpp.o
libparser.a: CMakeFiles/parser.dir/scan.cpp.o
libparser.a: CMakeFiles/parser.dir/build.make
libparser.a: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/redbase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libparser.a"
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: libparser.a

.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/requires: CMakeFiles/parser.dir/src/nodes.cc.o.requires
CMakeFiles/parser.dir/requires: CMakeFiles/parser.dir/src/interp.cc.o.requires
CMakeFiles/parser.dir/requires: CMakeFiles/parser.dir/parse.cpp.o.requires
CMakeFiles/parser.dir/requires: CMakeFiles/parser.dir/scan.cpp.o.requires

.PHONY : CMakeFiles/parser.dir/requires

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend: parse.cpp
CMakeFiles/parser.dir/depend: parse.hpp
CMakeFiles/parser.dir/depend: scan.cpp
	cd /home/ubuntu/redbase && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase /home/ubuntu/redbase/CMakeFiles/parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend

