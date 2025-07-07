cmake_minimum_required(VERSION 3.14)
project(fastp VERSION 1.0 LANGUAGES C CXX)

# Pick a C++ standard
# Tell CMake to build for both Intel and Apple Silicon
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Build architectures for macOS universal binary")

# Optionally force a minimum macOS version
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum macOS version")

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
