# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alejandromarcelo/Desktop/proyecto-streaming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alejandromarcelo/Desktop/proyecto-streaming/build

# Include any dependencies generated for this target.
include CMakeFiles/ProyectoProgra3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProyectoProgra3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProyectoProgra3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProyectoProgra3.dir/flags.make

CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/server.cpp
CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/server.cpp

CMakeFiles/ProyectoProgra3.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/server.cpp > CMakeFiles/ProyectoProgra3.dir/src/server.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/server.cpp -o CMakeFiles/ProyectoProgra3.dir/src/server.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/endpoints.cpp
CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/endpoints.cpp

CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/endpoints.cpp > CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/endpoints.cpp -o CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie.cpp
CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie.cpp

CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie.cpp > CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie.cpp -o CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie_database.cpp
CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie_database.cpp

CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie_database.cpp > CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/movie_database.cpp -o CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_system.cpp
CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_system.cpp

CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_system.cpp > CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_system.cpp -o CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/search_engine.cpp
CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/search_engine.cpp

CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/search_engine.cpp > CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/search_engine.cpp -o CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/trie.cpp
CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/trie.cpp

CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/trie.cpp > CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/trie.cpp -o CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/user.cpp
CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/user.cpp

CMakeFiles/ProyectoProgra3.dir/src/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/user.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/user.cpp > CMakeFiles/ProyectoProgra3.dir/src/user.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/user.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/user.cpp -o CMakeFiles/ProyectoProgra3.dir/src/user.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_factory.cpp
CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_factory.cpp

CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_factory.cpp > CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/recommendation_factory.cpp -o CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/authentication.cpp
CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/authentication.cpp

CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/authentication.cpp > CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/authentication.cpp -o CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.s

CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o: CMakeFiles/ProyectoProgra3.dir/flags.make
CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o: /Users/alejandromarcelo/Desktop/proyecto-streaming/src/globals.cpp
CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o: CMakeFiles/ProyectoProgra3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o -MF CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o.d -o CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o -c /Users/alejandromarcelo/Desktop/proyecto-streaming/src/globals.cpp

CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alejandromarcelo/Desktop/proyecto-streaming/src/globals.cpp > CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.i

CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alejandromarcelo/Desktop/proyecto-streaming/src/globals.cpp -o CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.s

# Object files for target ProyectoProgra3
ProyectoProgra3_OBJECTS = \
"CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o" \
"CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o"

# External object files for target ProyectoProgra3
ProyectoProgra3_EXTERNAL_OBJECTS =

bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/server.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/endpoints.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/movie.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/movie_database.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/recommendation_system.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/search_engine.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/trie.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/user.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/recommendation_factory.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/authentication.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/src/globals.cpp.o
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/build.make
bin/ProyectoProgra3: CMakeFiles/ProyectoProgra3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable bin/ProyectoProgra3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProyectoProgra3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProyectoProgra3.dir/build: bin/ProyectoProgra3
.PHONY : CMakeFiles/ProyectoProgra3.dir/build

CMakeFiles/ProyectoProgra3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProyectoProgra3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProyectoProgra3.dir/clean

CMakeFiles/ProyectoProgra3.dir/depend:
	cd /Users/alejandromarcelo/Desktop/proyecto-streaming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alejandromarcelo/Desktop/proyecto-streaming /Users/alejandromarcelo/Desktop/proyecto-streaming /Users/alejandromarcelo/Desktop/proyecto-streaming/build /Users/alejandromarcelo/Desktop/proyecto-streaming/build /Users/alejandromarcelo/Desktop/proyecto-streaming/build/CMakeFiles/ProyectoProgra3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ProyectoProgra3.dir/depend

