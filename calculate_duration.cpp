#include <iostream>
#include <chrono>
#include "nbody/BarnzNhutt.h"
#include "nbody/BarnzNhutt.cpp"

int main() {
    // Dynamically allocate memory for image, hdImage and bodies
    char *image = new char[WIDTH * HEIGHT * 3];
    double *hdImage = new double[WIDTH * HEIGHT * 3];
    struct body *bodies = new struct body[NUM_BODIES];

    // Call the initializeBodies function from BarnzNhutt.cpp to initialize properties of bodies
    initializeBodies(bodies);

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Call the function
    //exampleFunction();
    runSimulation(bodies, image, hdImage);

    // Stop measuring time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double, std::milli> duration = end - start;

    // Output the result
    std::cout << "Function execution time: " << duration.count() << " ms" << std::endl;

    // Deallocation
    delete[] bodies;
    delete[] image;
    delete[] hdImage;

    return 0;
}