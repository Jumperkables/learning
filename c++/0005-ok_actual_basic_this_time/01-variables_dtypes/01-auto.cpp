#include <iostream>

using namespace std;

string auto_info() {
    string auto_info = "The auto type\n";
    auto_info += "\t- Python style type inference at compile time\n";
    auto_info += "\t- Unlike Python, type will be FIXED afterwards\n";
    auto_info += "\t- auto deduces type from initialiser, evaluates the expression, and is simpler and more commonly used\n";
    auto_info += "\t- decltype extracts the exact type, doesnt evaluate the expression but only the type, and it more advanced and used in meta programming"
}

int main() {
    string info = auto_info();
    cout << info << endl; 
}