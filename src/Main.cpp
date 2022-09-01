#define MAIN 0

// if we want to track the memory allocation in this program then the new and delete operator overload definitions
// must be provided in the main.cpp. Hence set the flag TRACK_MEMORY accordingly.
#define TRACK_MEMORY 0
#if MAIN

int main(int argc, char const *argv[])
{

    return 0;
}

#if TRACK_MEMORY
// Definition of new and delete is deliberately kept here to avoid linking with the original new and delete definitions
// The below definitions should be activated when
#include "memoryTrace/MemoryAllocationMetrics.h"
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