#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdint>
#include <cuda_fp16.h>
#include <typeinfo>

using namespace std;
// -------------------------------------
// Functions

// Int Functions
int fib_int(int n) {
    if (n < 2) return n;
    return fib_int(n-1) + fib_int(n-2);
}
unsigned int fib_uint(unsigned int n) {
    if (n < 2) return n;
    return fib_uint(n-1) + fib_uint(n-2);
}
long fib_long(long n) {
    if (n < 2) return n;
    return fib_long(n-1) + fib_long(n-2);
}
uint8_t fib_uint8(uint8_t n) {
    if (n < 2) return n;
    return fib_uint8(n-1) + fib_uint8(n-2);
}
int8_t fib_int8(int8_t n) {
    if (n < 2) return n;
    return fib_int8(n-1) + fib_int8(n-2);
}
int16_t fib_int16(int16_t n) {
    if (n < 2) return n;
    return fib_int16(n-1) + fib_int16(n-2);
}
int32_t fib_int32(int32_t n) {
    if (n < 2) return n;
    return fib_int32(n-1) + fib_int32(n-2);
}
uint32_t fib_uint32(uint32_t n) {
    if (n < 2) return n;
    return fib_uint32(n-1) + fib_uint32(n-2);
}

// Float functions
float pi_leibniz_float(int n){
    float pi = 0.0;
    for (int i = 0; i < n; i++) {
        pi += ((i%2 == 0) ? 1:-1)/(2.0*i+1);
    }
    return pi*4;
}
double pi_leibniz_double(int n){
    double pi = 0.0;
    for (int i = 0; i < n; i++) {
        pi += ((i%2 == 0) ? 1:-1)/(2.0*i+1);
    }
    return pi*4;
}
double pi_leibniz_ldouble(int n){
    long double pi = 0.0;
    for (int i = 0; i < n; i++) {
        pi += ((i%2 == 0) ? 1:-1)/(2.0*i+1);
    }
    return pi*4;
}


void benchmarkIntOps() {
    cout << "Int ops" << endl;

    // time points
    chrono::time_point<chrono::system_clock> start_int, end_int;
    chrono::time_point<chrono::system_clock> start_uint, end_uint;
    chrono::time_point<chrono::system_clock> start_long, end_long;
    chrono::time_point<chrono::system_clock> start_uint8, end_uint8;
    chrono::time_point<chrono::system_clock> start_int8, end_int8;
    chrono::time_point<chrono::system_clock> start_int16, end_int16;
    chrono::time_point<chrono::system_clock> start_int32, end_int32;
    chrono::time_point<chrono::system_clock> start_uint32, end_uint32;

    // inputs
    int input_int = 42;
    unsigned int input_uint = 42;
    int input_long = 42;
    uint8_t input_uint8 = 42;
    int8_t input_int8 = 42;
    int16_t input_int16 = 42;
    int32_t input_int32 = 42;
    uint32_t input_uint32 = 42;

    // int
    start_int = chrono::system_clock::now();
    int result_int = fib_int(input_int);
    end_int = chrono::system_clock::now();
    chrono::duration<double> time_int = end_int - start_int;
    cout << "\t- int Fib(42) = " << time_int.count() << " | result: " << result_int << endl;

    // uint
    start_uint = chrono::system_clock::now();
    unsigned int result_uint = fib_uint(input_uint);
    end_uint = chrono::system_clock::now();
    chrono::duration<double> time_uint = end_uint - start_uint;
    cout << "\t- uint Fib(42) = " << time_uint.count() << " | result: " << result_uint << endl;

    // long
    start_long = chrono::system_clock::now();
    long result_long = fib_long(input_long);
    end_long = chrono::system_clock::now();
    chrono::duration<double> time_long = end_long - start_long;
    cout << "\t- long Fib(42) = " << time_long.count() << " | result: " << result_long << endl;


    // uint8
    start_uint8 = chrono::system_clock::now();
    uint8_t result_uint8 = fib_uint8(input_uint8);
    end_uint8 = chrono::system_clock::now();
    chrono::duration<double> time_uint8 = end_uint8 - start_uint8;
    cout << "\t- uint_8 Fib(42) = " << time_uint8.count() << " | result: " << result_uint8 << endl;

    // int8
    start_int8 = chrono::system_clock::now();
    int8_t result_int8 = fib_int8(input_int8);
    end_int8 = chrono::system_clock::now();
    chrono::duration<double> time_int8 = end_int8 - start_int8;
    cout << "\t- int_8 Fib(42) = " << time_int8.count() << " | result: " << result_int8 << endl;

    // int16
    start_int16 = chrono::system_clock::now();
    int16_t result_int16 = fib_int16(input_int16);
    end_int16 = chrono::system_clock::now();
    chrono::duration<double> time_int16 = end_int16 - start_int16;
    cout << "\t- int_16 Fib(42) = " << time_int16.count() << " | result: " << result_int16 << endl;

    // int32
    start_int32 = chrono::system_clock::now();
    int32_t result_int32 = fib_int32(input_int32);
    end_int32 = chrono::system_clock::now();
    chrono::duration<double> time_int32 = end_int32 - start_int32;
    cout << "\t- int_32 Fib(42) = " << time_int32.count() << " | result: " << result_int32 << endl;

    // int32
    start_uint32 = chrono::system_clock::now();
    uint32_t result_uint32 = fib_uint32(input_uint32);
    end_uint32 = chrono::system_clock::now();
    chrono::duration<double> time_uint32 = end_uint32 - start_uint32;
    cout << "\t- uint_32 Fib(42) = " << time_uint32.count() << " | result: " << result_uint32 << endl;
}

void benchmarkFloatOps() {
    cout << "Float ops" << endl;

    // time points
    chrono::time_point<chrono::system_clock> start_float, end_float;
    chrono::time_point<chrono::system_clock> start_double, end_double;
    chrono::time_point<chrono::system_clock> start_ldouble, end_ldouble;

    // inputs
    int input_float = 420000;
    int input_double = 420000;
    int input_ldouble = 420000;

    // float
    start_float = chrono::system_clock::now();
    float result_float = pi_leibniz_float(input_float);
    end_float = chrono::system_clock::now();
    chrono::duration<double> time_float = end_float - start_float;
    cout << std::setprecision(10) << "\t- float Leibniz(42000) = " << time_float.count() << " | result: " << result_float << endl;

    // double
    start_double = chrono::system_clock::now();
    double result_double = pi_leibniz_double(input_double);
    end_double = chrono::system_clock::now();
    chrono::duration<double> time_double = end_double - start_double;
    cout << std::setprecision(10) << "\t- double Leibniz(42000) = " << time_double.count() << " | result: " << result_double << endl;

    // long double
    start_ldouble = chrono::system_clock::now();
    double result_ldouble = pi_leibniz_ldouble(input_ldouble);
    end_ldouble = chrono::system_clock::now();
    chrono::duration<double> time_ldouble = end_ldouble - start_ldouble;
    cout << std::setprecision(10) << "\t- long double Leibniz(42000) = " << time_ldouble.count() << " | result: " << result_ldouble << endl;

}

void benchmarkPointerOps() {
    cout << "Pointer ops" << endl;
}