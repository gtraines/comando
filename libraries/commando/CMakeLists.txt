cmake_minimum_required(VERSION 3.8)
project(commando)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        examples/commands/commands.ino
        commando.cpp
        commando.h
        keywords.txt
        library.properties)

add_executable(commando ${SOURCE_FILES})