#include <iostream>

using namespace std;

string bool_info() {
    string bool_info = "Let me tell you about bools\n";
    bool_info += "\t- bool is 1 byte, 8 bits\n";
    bool_info += "\t- bools are implicitly converted between ints too\n";
    bool_info += "\t- bools could be 1 bit, but CPUs often access in 8 bits, byte, this efficiency, plus having an easier time with bitwise comparison operations (b & c) makes it more efficient overall\n";
    bool flag = true;
    flag = 0;
    flag = 1; // This works
    cout << 1+1 << endl;
    if (flag){
        cout << "SUCCESS" << endl;
    }
    return bool_info;
}


int main (){
    string info = bool_info();
    cout << info << endl;    
}