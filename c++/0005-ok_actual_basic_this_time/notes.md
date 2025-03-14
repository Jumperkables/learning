## Ok, Actual Basic Syntax this time
My previous day 0004 was supposed to be basic syntax, but since i'm already a very experienced programmer it was mostly abou the stuff different from python and geting experience with it.
- Building libraries and importing things in C++ etc
- How C++ deals with scope

#### Checking for leaks:
`valgrind --leak-check=full ./test`

Now, heres the actual basic syntax I'll need to briefly cover
- **GO TO EACH FILE FOR THE DETAILED NOTES ON EACH DTYPE**
#### 1. Variables and d-types
```cpp
int x = 10;             // Integer
double pi = 3.14;       // Floating-point
char c = 'A';           // Character
bool isTrue = true;     // Boolean
std::string name = "C++"; // String (requires #include <string>)

// Modern: auto & constexpr
auto y = 42;            // Compiler deduces type
constexpr double g = 9.81; // Compile-time constant
```

#### 2. Conditionals
```cpp
if (x > 5) {
    std::cout << "Greater than 5\n";
} else if (x == 5) {
    std::cout << "Exactly 5\n";
} else {
    std::cout << "Less than 5\n";
}

// Ternary Operator
int max = (a > b) ? a : b;
```

#### 3. Loops
```cpp
// For loop
for (int i = 0; i < 10; ++i) {
    std::cout << i << " ";
}

// While loop
int n = 0;
while (n < 5) {
    std::cout << n++ << " ";
}

// Do-while loop (executes at least once)
do {
    std::cout << "Runs at least once\n";
}  while (false);
```

#### 4. Ranged based loops C++11
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Read-only iteration
for (int num : vec) {
    std::cout << num << " ";
}

// Modify elements
for (int& num : vec) {
    num *= 2; 
}
```

#### 5. Switches
```cpp
switch (x) {
    case 1:
        std::cout << "One\n";
        break;
    case 2:
        std::cout << "Two\n";
        break;
    default:
        std::cout << "Other\n";
}
```

#### 6. Functions
```cpp
int add(int a, int b) {
    return a + b;
}

// Inline Function (Hint: Helps with performance for short functions)
inline int square(int x) { return x * x; }

// Function Overloading
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }

// Default Parameters
void greet(std::string name = "Guest") {
    std::cout << "Hello " << name << "\n";
}

// Pass-by-Reference (avoids copying large objects)
void increment(int& x) { x++; }

// Pass-by-Const-Reference (avoids copying, but prevents modification)
void print(const std::string& str) {
    std::cout << str;
}
```

#### 7. Arrays & Vectors
```cpp
// Raw array (C-style, not recommended)
int arr[5] = {1, 2, 3, 4, 5};

// Modern C++: Vector (dynamic array)
#include <vector>
std::vector<int> v = {10, 20, 30};
v.push_back(40);
```

#### 8. Pointers & References
```cpp
int a = 10;
int* ptr = &a;     // Pointer to a
std::cout << *ptr; // Dereferencing

int& ref = a;      // Reference (alias)
ref = 20;          // Modifies 'a'
```

#### 9. Smart Pointers (Modern)
```cpp
#include <memory>

std::unique_ptr<int> p1 = std::make_unique<int>(10);  // Unique ownership
std::shared_ptr
```

#### 10. Classes & OOP
```cpp
class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}  // Constructor

    void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

Person p("Alice", 25);
p.introduce();
```

#### 11. Lambda Functions (C++11)
```cpp
auto add = [](int a, int b) { return a + b; };
std::cout << add(5, 3);  // Output: 8
```

#### 12. Structs & Enums
```cpp
struct Point {
    int x, y;
};

enum Color { RED, GREEN, BLUE };
Color myColor = RED;
```

#### 13. File Handling
```cpp
#include <fstream>

// Writing to a file
std::ofstream outFile("output.txt");
outFile << "Hello, File!";
outFile.close();

// Reading from a file
std::ifstream inFile("output.txt");
std::string line;
while (getline(inFile, line)) {
    std::cout << line;
}
inFile.close();
```

#### 14. Exception Handling
```cpp
try {
    throw std::runtime_error("Something went wrong!");
} catch (const std::exception& e) {
    std::cout << "Caught: " << e.what();
}
```

#### 15. The constexpr Keyword (Compile-Time Constants)
```cpp
constexpr int square(int x) { return x * x; }
constexpr int result = square(5);  // Computed at compile-time
```