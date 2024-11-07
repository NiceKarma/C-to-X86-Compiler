#Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

#Set the project name and version
project(C-To-X86-Compiler VERSION 1.0)

#Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

#Include Directories
include_directories(include)

#Source Files
file(GLOB SOURCES "src/*.c")


#Create the executable
add_executable(MyCProject ${SOURCES})


#Compile Flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(MyCProject PRIVATE
                -g
                -Wall
                -Wextra
        )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(MyCProject PRIVATE
                -O2
        )
endif()


