#include <iostream>
#include "Utilities.h"

int main(int argc, char *argv[])
{
    LOG("This message should appear if the PR_RELEASE is set to anything but 1.");
    char *ptr = NEW(4);

    delete ptr;
    return 0;
}
