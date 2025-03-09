#include <iostream>
#include "h04.h"

int main() {

    std::cout << "Inputs number N: "; // I dont need to flush with newline    
    std::cin >> n;
    std::cout << "You chose: " << n << std::endl;
    bool isP = isPrime(n);

    if (isP == true) {
        std::cout << n << " is prime!" << std::endl;
    } else {
        std::cout << n << " is NOT prime!" << std::endl;
    }
}