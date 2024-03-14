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
CMAKE_SOURCE_DIR = /home/nlove/temp/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nlove/temp/server/build

# Include any dependencies generated for this target.
include tcp/CMakeFiles/tcp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tcp/CMakeFiles/tcp.dir/compiler_depend.make

# Include the progress variables for this target.
include tcp/CMakeFiles/tcp.dir/progress.make

# Include the compile flags for this target's objects.
include tcp/CMakeFiles/tcp.dir/flags.make

tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o: tcp/CMakeFiles/tcp.dir/flags.make
tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o: ../tcp/TcpConnection.cpp
tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o: tcp/CMakeFiles/tcp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nlove/temp/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o"
	cd /home/nlove/temp/server/build/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o -MF CMakeFiles/tcp.dir/TcpConnection.cpp.o.d -o CMakeFiles/tcp.dir/TcpConnection.cpp.o -c /home/nlove/temp/server/tcp/TcpConnection.cpp

tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp.dir/TcpConnection.cpp.i"
	cd /home/nlove/temp/server/build/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nlove/temp/server/tcp/TcpConnection.cpp > CMakeFiles/tcp.dir/TcpConnection.cpp.i

tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp.dir/TcpConnection.cpp.s"
	cd /home/nlove/temp/server/build/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nlove/temp/server/tcp/TcpConnection.cpp -o CMakeFiles/tcp.dir/TcpConnection.cpp.s

tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o: tcp/CMakeFiles/tcp.dir/flags.make
tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o: ../tcp/TcpServer.cpp
tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o: tcp/CMakeFiles/tcp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nlove/temp/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o"
	cd /home/nlove/temp/server/build/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o -MF CMakeFiles/tcp.dir/TcpServer.cpp.o.d -o CMakeFiles/tcp.dir/TcpServer.cpp.o -c /home/nlove/temp/server/tcp/TcpServer.cpp

tcp/CMakeFiles/tcp.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp.dir/TcpServer.cpp.i"
	cd /home/nlove/temp/server/build/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nlove/temp/server/tcp/TcpServer.cpp > CMakeFiles/tcp.dir/TcpServer.cpp.i

tcp/CMakeFiles/tcp.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp.dir/TcpServer.cpp.s"
	cd /home/nlove/temp/server/build/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nlove/temp/server/tcp/TcpServer.cpp -o CMakeFiles/tcp.dir/TcpServer.cpp.s

# Object files for target tcp
tcp_OBJECTS = \
"CMakeFiles/tcp.dir/TcpConnection.cpp.o" \
"CMakeFiles/tcp.dir/TcpServer.cpp.o"

# External object files for target tcp
tcp_EXTERNAL_OBJECTS =

../include/libtcp.so: tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o
../include/libtcp.so: tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o
../include/libtcp.so: tcp/CMakeFiles/tcp.dir/build.make
../include/libtcp.so: ../include/libthread.so
../include/libtcp.so: ../include/libreactor.so
../include/libtcp.so: ../include/libhttp.so
../include/libtcp.so: ../include/libcommon.so
../include/libtcp.so: tcp/CMakeFiles/tcp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nlove/temp/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../include/libtcp.so"
	cd /home/nlove/temp/server/build/tcp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tcp/CMakeFiles/tcp.dir/build: ../include/libtcp.so
.PHONY : tcp/CMakeFiles/tcp.dir/build

tcp/CMakeFiles/tcp.dir/clean:
	cd /home/nlove/temp/server/build/tcp && $(CMAKE_COMMAND) -P CMakeFiles/tcp.dir/cmake_clean.cmake
.PHONY : tcp/CMakeFiles/tcp.dir/clean

tcp/CMakeFiles/tcp.dir/depend:
	cd /home/nlove/temp/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nlove/temp/server /home/nlove/temp/server/tcp /home/nlove/temp/server/build /home/nlove/temp/server/build/tcp /home/nlove/temp/server/build/tcp/CMakeFiles/tcp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tcp/CMakeFiles/tcp.dir/depend

