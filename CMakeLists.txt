# Minimum required CMake version
cmake_minimum_required(VERSION 3.2)

# Create project
set(TARGET_NAME sbr-util)
project(${TARGET_NAME} LANGUAGES C CXX)

# Create 'sbr-util' executable target
add_executable(${TARGET_NAME}
    src/main.cpp
    src/SBR.c
)

# Add include directories
target_include_directories(${TARGET_NAME} PRIVATE src)   
