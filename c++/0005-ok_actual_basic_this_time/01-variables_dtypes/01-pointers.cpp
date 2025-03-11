#include <iostream>
using namespace std;

string pointer_info(){
    string info = "Pointers are used to track memory addresses of variables\n"; 
    info += "- A given variable doesn't store its own pointer, C++ internally keeps track of its location\n";
    info += "- & operator gives the address of a variable\n";
    info += "- * operator prints the value stored at the address of a giv=en pointer\n";
    info += "\t- This dereference is only defined for pointers. Accidentally using the wrong address gives an error\n";
    info += "- One can cast an integer or a memory address if they want, but its very risky, e.g. int* ptr = (int*)0x123456789;\n";
    info += "- A MEMORY LEAK is when we permanently lose memory because its still allocated, but no longer accessible\n";
    info += "\t- consider int* ptr = new int(42); inside a function\n";
    info += "\t- This will be placed in the hnks eap as dynamic memory\n";
    info += "\t- For efficiency, the C++ garbage collector doesn't go through the heap when functions end\n";
    info += "\t- So if i let the pointer `ptr` go out of scope without freeing the memory that pointer is pointing towards, I have no way of getting it back! The heap will just build on top of it because it wont overwrite it, but i have permanently lost memory which can add up with repeated function calls\n";
    info += "\t -In this way, this memory is said to have 'leaked' from the total 'vat' of memory available to the program\n";
    info += "- NOTE, the `new` keyword is better than malloc because it also call constructors (think __init__) functions for objects\n";
    info += "- std::unqiue_ptr and std::shared_ptr allocates to the stack instead of the heap, but importantly calls a 'free' during its destructor\n";
    info += "- This is why smart pointers use the stack, because they can actually go out of scope in the stack\n";
    info += "- i.e. The smart pointer object itself is on the stack and hence goes out of scope. The thing its pointing to is still on the heap as dynamic memory\n";
    info += "- std::unique_ptr allows only 1 pointer to own a resource\n";
    info += "- std::shared_ptr allows many to share, and frees once the final ptr is destructed\n";
    info += "- Broadly this is RAII: Resource acquisition is initialisation\n";

    info += "\n";
    // Practice
    int x = 42;
    int* p = &x;  // p stores the address of x
    cout << p << endl;  // Prints the memory address of x
    cout << *p << endl;  // Dereferencing: Prints 42 (the value stored at x)
    return info;
}


int main() {
    string output = pointer_info();
    cout << output << endl;
}