#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;


string int_info(){
    // Info about ints
    string info = "Int: Let me tell you about ints";
    info += "\t-Ints are typically 4 bytes, 32 bits, so anything above...";
    info += "\t-Ints in C++ can overflow\n";

    // C++ safe types
    int32_t safe_int = 4;   // Size is 4 bytes 32 bits
    int64_t safe_long = 8;  // Size is 64 bits
    int16_t safe_short = 2; // Size is 2 bytes
    uint8_t safe_uint = 1;  // Unsigned 8-bit


    int reg_int = pow(2, 31);
    cout << reg_int << reg_int;
    return info;
}

int main() {
    int_info();
}