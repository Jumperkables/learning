#include <iostream>

static std::string static_string = "Static String";
std::string global_string = "Global String";

std::string string_info(){
    // Info about ints
    std::string info = "std::string: Let me tell you about strings\n";
    info += "- C++ strings are mutable. They're not in Python\n";
    info += "- std::string each character is stored in 1 Byte\n";
    info += "- Theres a difference betweena char array and ";

    static_string[4] = '@';
    return info;

}