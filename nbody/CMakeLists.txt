# CMake configuration for the nbody subfolder


file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/images)

# Create a library target if you have shared code in nbody
add_library(NBodyLibrary
        BarnzNhutt.cpp
        # Add other source files here if you have more
)

# Link dependencies if needed (optional)
# target_link_libraries(NBodyLibrary <other_dependencies>)

# Create an executable specifically for BarnzNhutt.cpp (optional if needed)
# add_executable(BarnzNhuttExecutable BarnzNhutt.cpp)

# If using the library version, link this library with an executable in the main CMakeLists.txt
