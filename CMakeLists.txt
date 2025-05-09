cmake_minimum_required(VERSION 3.14)
project(fastp VERSION 1.0 LANGUAGES C CXX)

# Pick a C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Tell CMake where to look for our own headers
include_directories(${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_SOURCE_DIR}/src/zlib)

# Delegate to src/CMakeLists.txt
add_subdirectory(lib/libdeflate)
add_subdirectory(lib/libisal) 
add_subdirectory(src)
