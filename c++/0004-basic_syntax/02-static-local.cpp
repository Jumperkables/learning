#include <iostream>


// Write a function that counts how many times its been called
void foo () {
    static int x{0}; // This is a CONSTRUCTOR, only called the first time
    x = x+1;
    std::cout << "Called " << x << " times" << std::endl;
    // x is NOT destroyed here, but becomes inaccessible as it goes out of scope
}

int main () {
    foo();
    foo();
    foo();
    // error: 'x' was not declared in this scope: std::cout << "Called " << x << " times" << std::endl;
}