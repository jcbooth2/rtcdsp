cmake_minimum_required(VERSION 3.7...3.20)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(rtcdsp VERSION 0.1.0
               DESCRIPTION "A C implementation of real-time DSP algorithms."
               LANGUAGES C)

include(CTest)
enable_testing()

add_library(fifo src/fifo.c include/fifo.h)
target_include_directories(fifo PUBLIC include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
