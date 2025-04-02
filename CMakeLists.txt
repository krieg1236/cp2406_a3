cmake_minimum_required(VERSION 3.29)
project(CP2406_A3_StarterPack)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add the subdirectory for `nbody`
add_subdirectory(nbody)

# Include the subdirectory for headers in `nbody`
include_directories(nbody)

# Add the benchmarking source files in the main folder
add_executable(BenchmarkDuration calculate_duration.cpp)  # Benchmark execution time
add_executable(BenchmarkMemory calculate_memory.cpp)  # Benchmark memory usage

# Create an executable for the BarnzNhutt simulation in the `nbody` folder
add_executable(BarnzNhuttExecutable nbody/BarnzNhutt.cpp)

# Link the NBodyLibrary from the nbody subfolder to the BarnzNhuttExecutable
target_link_libraries(BarnzNhuttExecutable NBodyLibrary)

# Optionally set debugging flags if needed
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")