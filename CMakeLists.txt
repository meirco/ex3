cmake_minimum_required(VERSION 3.8)
project(ex3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Command.h
        Condition.h
        Expression.h
        LexParser.cpp
        LexParser.h
        Main.cpp
        OpenDataServer.cpp
        OpenDataServer.h
        ShuntingYardAlgo.cpp
        ShuntingYardAlgo.h)

add_executable(ex3 ${SOURCE_FILES})