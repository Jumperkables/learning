#include <iostream>

static std::string static_string = "Static String";
static const char* static_charArray = "Static char array";

std::string global_string = "Global String";

std::string string_info(){
    // Info about ints
    std::string info = "std::string: Let me tell you about strings\n";
    info += "- C++ strings are mutable. They're not in Python\n";
    info += "- std::string each character is stored in 1 Byte\n";
    info += "- Theres a difference between a char array and a std::string\n";
    info += "- If i need a small, fixed string, then const char* works better\n";
    info += "- Otherwise, std::string is modifiable and better\n\n";
    const char* extra_info = "Further info: the `const` keyword means that something must be initialised in delcaration\n";
    static_string[4] = '@';
    info = info + extra_info;
    return info;
}

int main() {
    std::string output = string_info();
    std::cout << output << std::endl;
}