//============================================================================
// This code snippet is separated from the BarnzNhutt.cpp to call and run the actual simulation. 
//============================================================================

// #include <omp.h>
#include <iostream>
#include "BarnzNhutt.h"

int main() {
    #ifdef FE_NOMASK_ENV
        if (DEBUG_INFO)
            // enable all hardware floating point exceptions for debugging
            feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);
    #endif
        std::cout << SYSTEM_THICKNESS << "AU thick disk\n";;
        char *image = new char[WIDTH * HEIGHT * 3];
        double *hdImage = new double[WIDTH * HEIGHT * 3];
        struct body *bodies = new struct body[NUM_BODIES];
    
        initializeBodies(bodies);
        runSimulation(bodies, image, hdImage);
        std::cout << "\nwe made it\n";
        delete[] bodies;
        delete[] image;
        return 0;
    }