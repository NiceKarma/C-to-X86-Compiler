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
CMAKE_SOURCE_DIR = /home/paul/Projects/c_to_x86_compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paul/Projects/c_to_x86_compiler/build

# Include any dependencies generated for this target.
include CMakeFiles/compile.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/compile.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/compile.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compile.dir/flags.make

CMakeFiles/compile.dir/src/asm_gen.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/asm_gen.c.o: ../src/asm_gen.c
CMakeFiles/compile.dir/src/asm_gen.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/compile.dir/src/asm_gen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/asm_gen.c.o -MF CMakeFiles/compile.dir/src/asm_gen.c.o.d -o CMakeFiles/compile.dir/src/asm_gen.c.o -c /home/paul/Projects/c_to_x86_compiler/src/asm_gen.c

CMakeFiles/compile.dir/src/asm_gen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/asm_gen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/asm_gen.c > CMakeFiles/compile.dir/src/asm_gen.c.i

CMakeFiles/compile.dir/src/asm_gen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/asm_gen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/asm_gen.c -o CMakeFiles/compile.dir/src/asm_gen.c.s

CMakeFiles/compile.dir/src/ast_tree.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/ast_tree.c.o: ../src/ast_tree.c
CMakeFiles/compile.dir/src/ast_tree.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/compile.dir/src/ast_tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/ast_tree.c.o -MF CMakeFiles/compile.dir/src/ast_tree.c.o.d -o CMakeFiles/compile.dir/src/ast_tree.c.o -c /home/paul/Projects/c_to_x86_compiler/src/ast_tree.c

CMakeFiles/compile.dir/src/ast_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/ast_tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/ast_tree.c > CMakeFiles/compile.dir/src/ast_tree.c.i

CMakeFiles/compile.dir/src/ast_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/ast_tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/ast_tree.c -o CMakeFiles/compile.dir/src/ast_tree.c.s

CMakeFiles/compile.dir/src/lexer.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/lexer.c.o: ../src/lexer.c
CMakeFiles/compile.dir/src/lexer.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/compile.dir/src/lexer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/lexer.c.o -MF CMakeFiles/compile.dir/src/lexer.c.o.d -o CMakeFiles/compile.dir/src/lexer.c.o -c /home/paul/Projects/c_to_x86_compiler/src/lexer.c

CMakeFiles/compile.dir/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/lexer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/lexer.c > CMakeFiles/compile.dir/src/lexer.c.i

CMakeFiles/compile.dir/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/lexer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/lexer.c -o CMakeFiles/compile.dir/src/lexer.c.s

CMakeFiles/compile.dir/src/main.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/main.c.o: ../src/main.c
CMakeFiles/compile.dir/src/main.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/compile.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/main.c.o -MF CMakeFiles/compile.dir/src/main.c.o.d -o CMakeFiles/compile.dir/src/main.c.o -c /home/paul/Projects/c_to_x86_compiler/src/main.c

CMakeFiles/compile.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/main.c > CMakeFiles/compile.dir/src/main.c.i

CMakeFiles/compile.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/main.c -o CMakeFiles/compile.dir/src/main.c.s

CMakeFiles/compile.dir/src/parser.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/parser.c.o: ../src/parser.c
CMakeFiles/compile.dir/src/parser.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/compile.dir/src/parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/parser.c.o -MF CMakeFiles/compile.dir/src/parser.c.o.d -o CMakeFiles/compile.dir/src/parser.c.o -c /home/paul/Projects/c_to_x86_compiler/src/parser.c

CMakeFiles/compile.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/parser.c > CMakeFiles/compile.dir/src/parser.c.i

CMakeFiles/compile.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/parser.c -o CMakeFiles/compile.dir/src/parser.c.s

CMakeFiles/compile.dir/src/print_ast.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/print_ast.c.o: ../src/print_ast.c
CMakeFiles/compile.dir/src/print_ast.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/compile.dir/src/print_ast.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/print_ast.c.o -MF CMakeFiles/compile.dir/src/print_ast.c.o.d -o CMakeFiles/compile.dir/src/print_ast.c.o -c /home/paul/Projects/c_to_x86_compiler/src/print_ast.c

CMakeFiles/compile.dir/src/print_ast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/print_ast.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/print_ast.c > CMakeFiles/compile.dir/src/print_ast.c.i

CMakeFiles/compile.dir/src/print_ast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/print_ast.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/print_ast.c -o CMakeFiles/compile.dir/src/print_ast.c.s

CMakeFiles/compile.dir/src/print_token_list.c.o: CMakeFiles/compile.dir/flags.make
CMakeFiles/compile.dir/src/print_token_list.c.o: ../src/print_token_list.c
CMakeFiles/compile.dir/src/print_token_list.c.o: CMakeFiles/compile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/compile.dir/src/print_token_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/compile.dir/src/print_token_list.c.o -MF CMakeFiles/compile.dir/src/print_token_list.c.o.d -o CMakeFiles/compile.dir/src/print_token_list.c.o -c /home/paul/Projects/c_to_x86_compiler/src/print_token_list.c

CMakeFiles/compile.dir/src/print_token_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compile.dir/src/print_token_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Projects/c_to_x86_compiler/src/print_token_list.c > CMakeFiles/compile.dir/src/print_token_list.c.i

CMakeFiles/compile.dir/src/print_token_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compile.dir/src/print_token_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Projects/c_to_x86_compiler/src/print_token_list.c -o CMakeFiles/compile.dir/src/print_token_list.c.s

# Object files for target compile
compile_OBJECTS = \
"CMakeFiles/compile.dir/src/asm_gen.c.o" \
"CMakeFiles/compile.dir/src/ast_tree.c.o" \
"CMakeFiles/compile.dir/src/lexer.c.o" \
"CMakeFiles/compile.dir/src/main.c.o" \
"CMakeFiles/compile.dir/src/parser.c.o" \
"CMakeFiles/compile.dir/src/print_ast.c.o" \
"CMakeFiles/compile.dir/src/print_token_list.c.o"

# External object files for target compile
compile_EXTERNAL_OBJECTS =

compile: CMakeFiles/compile.dir/src/asm_gen.c.o
compile: CMakeFiles/compile.dir/src/ast_tree.c.o
compile: CMakeFiles/compile.dir/src/lexer.c.o
compile: CMakeFiles/compile.dir/src/main.c.o
compile: CMakeFiles/compile.dir/src/parser.c.o
compile: CMakeFiles/compile.dir/src/print_ast.c.o
compile: CMakeFiles/compile.dir/src/print_token_list.c.o
compile: CMakeFiles/compile.dir/build.make
compile: CMakeFiles/compile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paul/Projects/c_to_x86_compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable compile"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compile.dir/build: compile
.PHONY : CMakeFiles/compile.dir/build

CMakeFiles/compile.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compile.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compile.dir/clean

CMakeFiles/compile.dir/depend:
	cd /home/paul/Projects/c_to_x86_compiler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paul/Projects/c_to_x86_compiler /home/paul/Projects/c_to_x86_compiler /home/paul/Projects/c_to_x86_compiler/build /home/paul/Projects/c_to_x86_compiler/build /home/paul/Projects/c_to_x86_compiler/build/CMakeFiles/compile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/compile.dir/depend

