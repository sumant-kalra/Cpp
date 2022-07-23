#define MAIN 1
// if we want to track the memory allocation in this program then the new and delete operator overload definitions
// must be provided in the main.cpp. Hence set the flag TRACK_MEMORY accordingly.
#define TRACK_MEMORY 1
#if MAIN

#include <iostream>
#include <memory>
#include <memoryTrace/MemoryAllocationMetrics.h>

struct Demo
{
    int x = 0;
    float y = 0;
    int z = 0;
};

int main(int argc, char const *argv[])
{
    Demo *ptr_obj = new Demo;
    metrics::MemoryAllocationMetrics::printMemoryUsage();

    delete ptr_obj;
    metrics::MemoryAllocationMetrics::printMemoryUsage();

    {
        std::unique_ptr<Demo> ptrDemo = std::make_unique<Demo>();
        metrics::MemoryAllocationMetrics::printMemoryUsage();
    }
    metrics::MemoryAllocationMetrics::printMemoryUsage();

    std::string name = "This is my Memory Tracker Program";
    metrics::MemoryAllocationMetrics::printMemoryUsage();

    return 0;
}

#if TRACK_MEMORY
// Definition of new and delete is deliberately kept here to avoid linking with the original new and delete definitions
// The below definitions should be activated when

void *operator new(size_t sizeInBytes)
{
    metrics::MemoryAllocationMetrics::addMemory(sizeInBytes);

    // Allocating extra bytes
    size_t totalBytesToAllocate = sizeof(size_t) + sizeInBytes;
    void *ptr = malloc(totalBytesToAllocate);

    // Storing the size information in the extra bytes allocated in the front
    size_t *ptr1 = (size_t *)ptr;
    ptr1[0] = sizeInBytes;

    return (void *)&ptr1[1];
}

void operator delete(void *ptr)
{
    // Retrieve the size information
    size_t *ptr1 = (size_t *)ptr;
    size_t sizeInBytes = ptr1[-1];

    metrics::MemoryAllocationMetrics::clearMemory(sizeInBytes);

    // Free the memory allocated originally
    free((void *)&(ptr1[-1]));
}
#endif

#endif