#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <psapi.h>
#elif defined(__APPLE__) && defined(__MACH__)
#include <mach/mach.h>
#include <unistd.h>
#endif

#include "nbody/BarnzNhutt.h"
#include "nbody/BarnzNhutt.cpp"

#if defined(_WIN32) || defined(_WIN64)
SIZE_T getMemoryUsage() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *) &pmc, sizeof(pmc));
    return pmc.WorkingSetSize;
}
#elif defined(__APPLE__) && defined(__MACH__)
size_t getMemoryUsage() {
    struct mach_task_basic_info info;
    mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &infoCount) != KERN_SUCCESS) {
        return 0;
    }
    return info.resident_size;
}
#endif

int main() {

    // Dynamically allocate memory for image, hdImage and bodies
    char *image = new char[WIDTH * HEIGHT * 3];
    double *hdImage = new double[WIDTH * HEIGHT * 3];
    struct body *bodies = new struct body[NUM_BODIES];

    // Call the initializeBodies function from BarnzNhutt.cpp to initialize properties of bodies
    initializeBodies(bodies);
    // Get initial memory usage
    auto initial_memory = getMemoryUsage();

    // Call the function
    runSimulation(bodies, image, hdImage);

    // Get memory usage after the function call
    auto final_memory = getMemoryUsage();

    std::cout << "Memory used by function: " << (final_memory - initial_memory) / 1024 << " KB" << std::endl;

    // Deallocation
    delete[] bodies;
    delete[] image;
    delete[] hdImage;

    return 0;
}
