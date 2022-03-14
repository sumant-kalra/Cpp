#ifndef UTILITIES_H
#define UTILITIES_H

// Logging system based on the preprocessor definition
#if PR_RELEASE == 1
#define LOG(x)
#else
#define LOG(x) std::cout << x << "\n";
#endif

#if 0
#define MAIN    \
    int main()  \
    {           \
        LOG(4); \
    }
#endif

// Track memory allocation - FileName, LineNumber and Size of allocation in bytes
#include <new>
// The new function defined below does not throw exception but assigns a nullptr
// x is the number of bytes to be allocated
#define NEW(x)                  \
    new (std::nothrow) char(x); \
    std::cout << "[Heap memory allocation] \n File name: " << __FILE__ << "; Line number: " << __LINE__ << "; Bytes allocated: " << x << "\n";

#endif