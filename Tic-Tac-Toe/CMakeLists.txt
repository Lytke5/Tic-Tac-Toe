cmake_minimum_required(VERSION 3.5)

project(Tic-Tac-Toe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Tic-Tac-Toe main.cpp)

install(TARGETS Tic-Tac-Toe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
