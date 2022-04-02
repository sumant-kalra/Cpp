#include "Polymorphism.h"

int main(int argc, char *argv[])
{
    polymorphic::Enemy *obj1 = new polymorphic::Enemy();
    polymorphic::Player *obj2 = new polymorphic::Player();

    polymorphic::printEntityType(obj1);
    polymorphic::printEntityType(obj2);

    delete obj1;

    return 0;
}
