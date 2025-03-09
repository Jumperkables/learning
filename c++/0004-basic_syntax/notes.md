## Basic Syntax and Program Execution
Getting used to the basic expected syntax in C++

#### Fun Rules:
- When compiling multiple `.cpp` files together, only ONE of them may have `main` (or any other variable i think) defined.
- Breaking down `std::cout` and `#include <iostream>`
    * `cout` stands for character out, i never knew that
    * `std::` is accessing the `std` namespace
    * On `#include` syntax:
        + `<iostream>` squarebrackets `<>` tell the compiler to look in the system include directorys (where standard library headers are)
        + `"myprogram"` tells the compiler to look in the cirrent directory first (wherever the source code is)
- Header files and `#ifndef`
    * Looking carefully at `#ifndef`, you'll see it acts as a flag to make sure the variables its guarding are only ever declared once even if multiple `.cpp` files import it
    * Header files don't get compiled seperately, they get included in `.cpp` files which are compiled. You actually can't compile them.
- Global variables MUST be initialised in the same statement that declares them unless they are marked as `extern` or `static`
    * `extern` tells the compiler "This variable exists somewhere, but its defined elsewhere in some other file or later on in the file.
        - The linker (last stage) then resolves `x` when combining other files into the final program
        - If `x` isn't actually defined anywhere, then an undefined reference is shown at linking time
    * `static` for `global` changes scope and lifetime of a variable to stay inside its own file
        - Normal global variable is accessible from all files in program
        - Prevents **accidental name clashes** when multiple files have the same global variable
    * `static` for `local` variables allows them to persist and not be destroyed on return. But they DO **go out of scope**
        - Useful as counters
    * The reason global variables need to be initialised or assigned is because **standalone assignments require execution. which happens at RUNTIME and NOT compile time.**
```cpp
int d;
d = 10; // NOT ALLOWED
int e = 10; // ALLOWED

int main() {
    // stuff
}
```
- `MACRO`
    * The modern C++ alternative to macros is `constexpr`
        + `constexpr double PI = 3.14159;`
        + Type safety
        + 'Compile time inlining'
- `inline`
    `inline int square(int x) {`
    * Remove function call overhead (literally tells the compiler to paste the C++ in there)
    * Good for maths and small getter setter
    * Bad for large calls
    * `inline` **IS JUST A SUGGESTION TO THE COMPILER**
- 