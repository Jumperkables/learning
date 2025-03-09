#include <iostream>

int c = 17;  // In BSS uninitialised data segment
int d = c; // In intialised data segment

void func(int a, int b) {
    int result = a + b; // Stack variable
    int* heapVar = new int(42); // Heap allocation
    std::cout << "Result: " << result << ", HeapVar: " << *heapVar << std::endl;
    delete heapVar; // Free memory
}

int main() {
    c = 12;
    int x;  // Stack variable
    x = 5;
    int y = 10; // Stack variable
    func(x, y);
    std::cout << "c is in uninitialised data segment (BSS): " << c << std::endl;
    std::cout << "d is the initialised data segment: " << d << std::endl;
    return 0;
}