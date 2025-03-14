#include <iostream>
#include <memory>
using namespace std;

weak_ptr<int> wPtr;

string pointer_info(){
    string info = "Pointers are used to track memory addresses of variables\n"; 
    info += "\t-A given variable doesn't store its own pointer, C++ internally keeps track of its location\n";
    info += "\t-& operator gives the address of a variable\n";
    info += "\t-* operator prints the value stored at the address of a giv=en pointer\n";
    info += "\t\t-This dereference is only defined for pointers. Accidentally using the wrong address gives an error\n";
    info += "\t-One can cast an integer or a memory address if they want, but its very risky, e.g. int* ptr = (int*)0x123456789;\n";
    info += "\t-A MEMORY LEAK is when we permanently lose memory because its still allocated, but no longer accessible\n";
    info += "\t\t-consider int* ptr = new int(42); inside a function\n";
    info += "\t\t-This will be placed in the hnks eap as dynamic memory\n";
    info += "\t\t-For efficiency, the C++ garbage collector doesn't go through the heap when functions end\n";
    info += "\t\t-So if i let the pointer `ptr` go out of scope without freeing the memory that pointer is pointing towards, I have no way of getting it back! The heap will just build on top of it because it wont overwrite it, but i have permanently lost memory which can add up with repeated function calls\n";
    info += "\t -In this way, this memory is said to have 'leaked' from the total 'vat' of memory available to the program\n";
    info += "\t-NOTE, the `new` keyword is better than malloc because it also call constructors (think __init__) functions for objects\n";
    info += "\t-std::unqiue_ptr and std::shared_ptr allocates to the stack instead of the heap, but importantly calls a 'free' during its destructor\n";
    info += "\t-This is why smart pointers use the stack, because they can actually go out of scope in the stack\n";
    info += "\t-i.e. The smart pointer object itself is on the stack and hence goes out of scope. The thing its pointing to is still on the heap as dynamic memory\n";
    info += "\t-std::unique_ptr allows only 1 pointer to own a resource\n";
    info += "\t-std::shared_ptr allows many to share, and frees once the final ptr is destructed\n";
    info += "\t-Broadly this is RAII: Resource acquisition is initialisation\n";
    info += "\t-Look at challenge 3 in this file for explanation on how array are and are not pointers. They are not exactly pointers. Notably, they can't be modified, where true pointers can be reassigned.";

    // Challenge 1:
    if (false){
        int a = 10;
        int b = 20;
        int* ptrA = &a;
        int* ptrB = &b;
        ptrA = ptrB;
        *ptrA = 30;
        cout << a << endl; // a will be 10
        cout << b << endl; // b will be 30
    }

    // Challenge 2:
    if (false){
        int a = 5;
        int* ptrA = &a;
        int** ptrB = &ptrA;
        cout << a << endl;      // 5
        cout << *ptrA << endl;  // 5
        cout << **ptrB << endl; // 5
        **ptrB = 6;
        cout << a << endl;  // 6
    }

    // Challenge 3:
    if (false){
        int arr[] = {10, 20, 30, 40}; // arr is not exactly a pointer -- its still an array type -- but it is implicitly coverted or decayed into a pointer under most expressions, e.g. printing.
        int* ptr = arr;
        cout << *(arr-1) << endl;
    }

    return info;
}

// Challenge 4:
void createNumber() {
    unique_ptr<int> ptr(new int(42));
    cout << *ptr << endl;
}

// Challenge 5:
void sharedPtr() {
    shared_ptr sPtr = make_shared<int>(43);
    wPtr = sPtr;
    cout << "Inside Function: sPtr use count = " << sPtr.use_count() << endl;
    cout << "Inside Function: wPtr use count = " << wPtr.use_count() << endl;
}

// Challenge 6:
struct Node {
    int value;
    shared_ptr<Node> next;  // Shared pointer to another Node

    Node(int val) : value(val) {
        cout << "Node created: " << value << "\n";
    }

    ~Node() {
        cout << "Node destroyed: " << value << "\n";
    }
};

//int main() {
//    string output = pointer_info();
//    cout << output << endl << endl;
//    cout << "Learning about smart pointers" << endl;
//    createNumber();
//    sharedPtr();
//    cout << "Outside Function: wPtr use count = " << wPtr.use_count() << endl;
//    if (wPtr.expired()){
//        cout << "Memory Freed" << endl;
//    } else {
//        cout << "Memory still exists. Possible leak" << endl;
//    }
//
//    // Counters and structs
//    shared_ptr<Node> n1 = make_shared<Node>(1);
//    shared_ptr<Node> n2 = make_shared<Node>(2);
//    n1->next = n2;  // -> is 'dereference and access'. remember n1 is a pointer.
//    n2->next = n1;  // (*n1).next
//}