#ifndef MEMORY_ALLOCATION_METRICS_H
#define MEMORY_ALLOCATION_METRICS_H

#include <iostream>

namespace metrics
{
    class MemoryAllocationMetrics
    {
    private:
        static int s_totalHeapAllocated;
        static int s_totalHeapDeleted;

    public:
        static void addMemory(size_t size);

        static void clearMemory(size_t size);

        static void printMemoryUsage();

        MemoryAllocationMetrics() = delete;
        MemoryAllocationMetrics(const MemoryAllocationMetrics &) = delete;
    };

}

#endif