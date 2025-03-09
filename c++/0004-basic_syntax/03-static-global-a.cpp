#include <iostream>

static int staticGlobal = 42;
int normalGlobal = 43;

void printNormalGlobal() {
    std::cout << "Normal Global" << normalGlobal << std::endl;
}

void printStaticGlobal() {
    std::cout << "Static Global" << staticGlobal << std::endl;
}

// This DOES Print
//int main() {
//    // Both static and non-static globals can be seen here
//    std::cout << "Inside filea - main func" << std::endl;
//    printNormalGlobal();
//    printStaticGlobal();
//    return 0 ;
//}