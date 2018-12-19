cmake_minimum_required(VERSION 3.13)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3 main.cpp lexParser.cpp lexParser.h openDataServer.cpp openDataServer.h command.cpp shuntingYardAlgo.cpp shuntingYardAlgo.h expression.h condition.h)