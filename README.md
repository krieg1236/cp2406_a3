# cp2406_a3
A repository for the CP2406 Assignment 3

### Directory layout

    ├── CP2406                    # Test files (alternatively `spec` or `tests`)
    │   ├── images                # images .ppm folder
    |   ├── ├──...                # .ppm generated from the simulation
    │   ├── BarnzNhutt.cpp        # Barnes-Hut function implementations
    │   ├── BarnzNhutt.h          # Function declarations
    │   ├── Bhtree.cpp            # Barnes-Hut tree logic
    │   ├── Constants.h           # Constants (e.g., NUM_BODIES, WIDTH, HEIGHT)
    │   ├── Octant.cpp            # Octant calculations
    │   ├── CMakeLists.txt        # CMake config for simulation components
    │   ├── RunSimulation.cpp     # Runs the actual simulation
    ├── calculate_duration.cpp    # Execution time benmchmark
    ├── calculate_memory.cpp      # Memory usage benchmark
    └── CMakeLists.txt            # Main CMakeLists file

To make BarnzNhutt.cpp modular and reusable, the function declarations will be migrated to a separate header file called BarnzNhutt.h and the main funciton will be migrated to RunSimulation.cpp where the actual simulation will be executed.
