#include "MemoryAllocationMetrics.h"

int metrics::MemoryAllocationMetrics::s_totalHeapAllocated = 0;
int metrics::MemoryAllocationMetrics::s_totalHeapDeleted = 0;

void metrics::MemoryAllocationMetrics::addMemory(size_t size)
{
    s_totalHeapAllocated += size;
}

void metrics::MemoryAllocationMetrics::clearMemory(size_t size)
{
    s_totalHeapDeleted += size;
}

void metrics::MemoryAllocationMetrics::printMemoryUsage()
{
    std::cout << "\n";
    std::cout << "========== Memory Allocation Metrics =========\n";
    std::cout << "Total memory allocated on heap: " << s_totalHeapAllocated << "\n";
    std::cout << "Total memory deleted from heap: " << s_totalHeapDeleted << "\n";
    std::cout << "Current allocation on heap: " << s_totalHeapAllocated - s_totalHeapDeleted << "\n";
    std::cout << "\n";
}
