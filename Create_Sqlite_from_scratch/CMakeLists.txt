cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(sqlite_scratch LANGUAGES CXX)

set(CMAKE_BUILD_TYPE "Release")
set(OpenGL_GL_PREFERENCE  GLVND)
add_definitions("-DENABLE_SSE")

set(CMAKE_CXX_FLAGS "-std=c++17 -O3 -pthread -Wall -Ofast -Wfatal-errors -D_MWAITXINTRIN_H_INCLUDED")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME}
    constant.h
    CommandProcessor.h
    CommandProcessor.cpp
    Pager.h
    Pager.cpp
    main.cpp
    )
