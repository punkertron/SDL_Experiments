# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/
# cmake --build ./build

cmake_minimum_required(VERSION 3.25.1)

project("SDL2 Experiments")

# add warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Find the SDL2 package (this makes SDL2 available)
find_package(SDL2 REQUIRED)

# Define the path to the common include directory
set(COMMON_INC_DIR "${CMAKE_SOURCE_DIR}/common_inc")

# Add subdirectories containing executables
add_subdirectory(simple_triangle)
