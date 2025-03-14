#include <iostream>
#include <cmath>

using namespace std;

string double_info() {
    string double_info = "";
    double_info += "Let me tell you about doubles\n";
    double_info += "\t- 8 byte 64 bit float\n";
    double_info += "\t- Float 4 bytes, and long double\n";
    double_info += "\t- long doubles are usually 80 bits\n";
    long double ld = 2.0;
    // No safer version of double
    double d = 2.0;
    d = pow(d, 63);
    cout << d << endl;
    return double_info;
}

int main() {
    string info = double_info();
    cout << info << endl;
}