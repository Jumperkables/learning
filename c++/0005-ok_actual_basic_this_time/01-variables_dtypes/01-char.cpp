#include <iostream>
#include <cstdint>

using namespace std;

string char_info() {
    string char_info = "Here are some things about chars\n";
    char_info += "\t- chars store single characters, 1 byte, 8 bits\n";
    char_info += "\t- They do NOT store more than one char\n";
    char_info += "\t- They don't store unicode, so use wchar_t \n";
    wchar_t uni = 'I';
    // char     = 8-bit
    // wchar_t  = 16-bit
    // char16_t = 16 bit
    // char32_t = 32 bit
    uint8_t safe_uint = 1;  // Unsigned 8-bit char
    return char_info;
}

int main (){
    string info = char_info();
    cout << info << endl;
}