# Minimum required CMake version
cmake_minimum_required(VERSION 3.2)

# Create project
set(TARGET_NAME SBR)
project(${TARGET_NAME} LANGUAGES C CXX)

# Create 'SBR' library
add_library(${TARGET_NAME}
    src/SBR.c
)

# Add include directories
target_include_directories(${TARGET_NAME} PUBLIC include)

# Options
option(SBR_BUILD_EXAMPLES "Build examples" OFF)
option(SBR_BUILD_TESTS "Build tests" OFF)

if(SBR_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(SBR_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()