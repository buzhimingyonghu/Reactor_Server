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
CMAKE_SOURCE_DIR = /home/nlove/temp/Reactor_Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nlove/temp/Reactor_Server/build

# Include any dependencies generated for this target.
include reactor/CMakeFiles/reactor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include reactor/CMakeFiles/reactor.dir/compiler_depend.make

# Include the progress variables for this target.
include reactor/CMakeFiles/reactor.dir/progress.make

# Include the compile flags for this target's objects.
include reactor/CMakeFiles/reactor.dir/flags.make

reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.o: reactor/CMakeFiles/reactor.dir/flags.make
reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.o: ../reactor/Dispatcher.cpp
reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.o: reactor/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nlove/temp/Reactor_Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.o"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.o -MF CMakeFiles/reactor.dir/Dispatcher.cpp.o.d -o CMakeFiles/reactor.dir/Dispatcher.cpp.o -c /home/nlove/temp/Reactor_Server/reactor/Dispatcher.cpp

reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/Dispatcher.cpp.i"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nlove/temp/Reactor_Server/reactor/Dispatcher.cpp > CMakeFiles/reactor.dir/Dispatcher.cpp.i

reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/Dispatcher.cpp.s"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nlove/temp/Reactor_Server/reactor/Dispatcher.cpp -o CMakeFiles/reactor.dir/Dispatcher.cpp.s

reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.o: reactor/CMakeFiles/reactor.dir/flags.make
reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.o: ../reactor/EpollDispatcher.cpp
reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.o: reactor/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nlove/temp/Reactor_Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.o"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.o -MF CMakeFiles/reactor.dir/EpollDispatcher.cpp.o.d -o CMakeFiles/reactor.dir/EpollDispatcher.cpp.o -c /home/nlove/temp/Reactor_Server/reactor/EpollDispatcher.cpp

reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/EpollDispatcher.cpp.i"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nlove/temp/Reactor_Server/reactor/EpollDispatcher.cpp > CMakeFiles/reactor.dir/EpollDispatcher.cpp.i

reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/EpollDispatcher.cpp.s"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nlove/temp/Reactor_Server/reactor/EpollDispatcher.cpp -o CMakeFiles/reactor.dir/EpollDispatcher.cpp.s

reactor/CMakeFiles/reactor.dir/EventLoop.cpp.o: reactor/CMakeFiles/reactor.dir/flags.make
reactor/CMakeFiles/reactor.dir/EventLoop.cpp.o: ../reactor/EventLoop.cpp
reactor/CMakeFiles/reactor.dir/EventLoop.cpp.o: reactor/CMakeFiles/reactor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nlove/temp/Reactor_Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object reactor/CMakeFiles/reactor.dir/EventLoop.cpp.o"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT reactor/CMakeFiles/reactor.dir/EventLoop.cpp.o -MF CMakeFiles/reactor.dir/EventLoop.cpp.o.d -o CMakeFiles/reactor.dir/EventLoop.cpp.o -c /home/nlove/temp/Reactor_Server/reactor/EventLoop.cpp

reactor/CMakeFiles/reactor.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reactor.dir/EventLoop.cpp.i"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nlove/temp/Reactor_Server/reactor/EventLoop.cpp > CMakeFiles/reactor.dir/EventLoop.cpp.i

reactor/CMakeFiles/reactor.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reactor.dir/EventLoop.cpp.s"
	cd /home/nlove/temp/Reactor_Server/build/reactor && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nlove/temp/Reactor_Server/reactor/EventLoop.cpp -o CMakeFiles/reactor.dir/EventLoop.cpp.s

# Object files for target reactor
reactor_OBJECTS = \
"CMakeFiles/reactor.dir/Dispatcher.cpp.o" \
"CMakeFiles/reactor.dir/EpollDispatcher.cpp.o" \
"CMakeFiles/reactor.dir/EventLoop.cpp.o"

# External object files for target reactor
reactor_EXTERNAL_OBJECTS =

../include/libreactor.so: reactor/CMakeFiles/reactor.dir/Dispatcher.cpp.o
../include/libreactor.so: reactor/CMakeFiles/reactor.dir/EpollDispatcher.cpp.o
../include/libreactor.so: reactor/CMakeFiles/reactor.dir/EventLoop.cpp.o
../include/libreactor.so: reactor/CMakeFiles/reactor.dir/build.make
../include/libreactor.so: reactor/CMakeFiles/reactor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nlove/temp/Reactor_Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../../include/libreactor.so"
	cd /home/nlove/temp/Reactor_Server/build/reactor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reactor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
reactor/CMakeFiles/reactor.dir/build: ../include/libreactor.so
.PHONY : reactor/CMakeFiles/reactor.dir/build

reactor/CMakeFiles/reactor.dir/clean:
	cd /home/nlove/temp/Reactor_Server/build/reactor && $(CMAKE_COMMAND) -P CMakeFiles/reactor.dir/cmake_clean.cmake
.PHONY : reactor/CMakeFiles/reactor.dir/clean

reactor/CMakeFiles/reactor.dir/depend:
	cd /home/nlove/temp/Reactor_Server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nlove/temp/Reactor_Server /home/nlove/temp/Reactor_Server/reactor /home/nlove/temp/Reactor_Server/build /home/nlove/temp/Reactor_Server/build/reactor /home/nlove/temp/Reactor_Server/build/reactor/CMakeFiles/reactor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : reactor/CMakeFiles/reactor.dir/depend

