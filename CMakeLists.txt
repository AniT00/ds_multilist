cmake_minimum_required(VERSION 3.26)

project(lab1)

set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include")
set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")

add_subdirectory("src")
add_subdirectory("test")