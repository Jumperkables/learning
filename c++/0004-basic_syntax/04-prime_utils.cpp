#include <iostream>

int n = 0;

bool isPrime(int x) {
    for(int i=2; i<x; i++) {
        std::cout << i << " | " << (x%i) << std::endl;
        if( (x%i) == 0 ) {
            std::cout << x << " is NOT prime - Divisible by: " << i << std::endl;
            return false;
        }
    }
    std::cout << x << " is prime" << std::endl;
    return true;
}