#include <iostream>
#include "h03.h"

extern int normalGlobal;

void tryPrintStaticGlobal() {
    // CAN print the normal global from file-a
    std::cout << "normal global from file a " << normalGlobal << std::endl;

    // Can't print the static global from file-a
    // This Will not compile
    std::cout << "static global from file a" << staticGlobal << std::endl;
}

int main() {
    std::cout << "inside file b - main function" << std::endl;
    tryPrintStaticGlobal();
    return 0;
}