#include <iostream>

#include "benchmark.h"
#include "memory_safety.h"

using namespace std;

int main() {
    cout << "BENCHMARKING" << endl;
    benchmarkIntOps();
    benchmarkFloatOps();
    benchmarkPointerOps();
    cout << "\n\n";

    cout << "TESTING POINTERS" << endl;
    testRawPointers();
    testSmartPointers();
    cout << "\n\n";

    cout << "Program ending" << endl;
}