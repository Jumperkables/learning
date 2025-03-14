# Most Efficient Choices for Types

## 1. Ints and Numerics
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Small Integer (0 - 255) | `uint8_t` (from `<cstdint>`) |	1 byte, fixed-size unsigned type. Efficient for small positive integers (e.g., byte-level operations). |
| Small Integer (signed, 0 - 127) | `int8_t` | 1 byte, signed integer. Efficient for small ranges with negative values. |
| Small to Medium Integer (0 - 65,535) | `uint16_t` (from `<cstdint>`) | 2 bytes, efficient for unsigned integers in this range. |
| Medium Integer (0 - 4 billion) | `uint32_t` (from `<cstdint>`) | 4 bytes, common for unsigned integers. Efficient for typical data and array indexing. |
| Signed Medium Integer (0 - 2 billion) | `int32_t` (from `<cstdint>`) | 4 bytes, signed integer for moderate-sized integers. |
| Large Integer (up to 9 quintillion) | `uint64_t` (from `<cstdint>`) | 8 bytes, useful for large unsigned integers with a large range. |
| Large Signed Integer | `int64_t` (or `long long`) | 8 bytes, for large signed integers. Provides good range for large calculations. |
| Floating Point (Single Precision) | `float` | 4 bytes, for single-precision floating point numbers. Ideal for performance-sensitive applications (like graphics). |
| Floating Point (Double Precision) | `double` | 8 bytes, the default for higher precision floating-point numbers. Used in scientific computing. |
| High Precision Floating Point | `long double` | Typically 8, 12, or 16 bytes depending on platform. Provides high precision, though potentially less efficient. |
| Fixed-Point Arithmetic (integer-based) | `int32_t` or `int64_t` | Useful for fixed-point arithmetic (commonly used in graphics and some ML applications). |


## 2. String and Char Types
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Single Characters | `char` or `unsigned char` | 1 byte, minimal storage for ASCII characters or byte-level operations. |
| Fixed-Size String | `char[]` | Use for low-level, fixed-length character arrays. Efficient for buffer management. |
| Dynamic Text | `std::string` | Built-in dynamic string management, handles memory allocation automatically. Ideal for text manipulation. |
| Wide Characters (Unicode) | `wchar_t` or `std::wstring` | Used for wider characters, typically 2 or 4 bytes, supports Unicode characters. |
| Unicode (UTF-8 Encoding) | `std::string` (with UTF-8 encoded) | `std::string` can handle UTF-8 encoded characters. Use with caution for multi-byte characters. |


## 3. Iterators and Loop Controls
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Looping over Containers | `auto&` (reference type) | Avoids unnecessary copying. auto& is most efficient for container iteration. |
| Constant Reference Iteration | `const auto&` | For read-only access to elements. Avoids copying and allows for safe modification. |
| Simple Loop Index | `int` or `size_t` | `int` or `size_t` are most commonly used for small to large index ranges. `size_t` is preferred for sizes. |
| Pointer-style iteration | `auto*` | For working with raw pointers, like iterating through arrays or memory regions. |


## 4. Lists, Dicts, Containers
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Small Fixed-Size Containers | `std::array<T, N>` | Efficient, compile-time size fixed array. No overhead, highly optimized. |
| Dynamic Array | `std::vector<T>` | Efficient dynamic resizing array, automatically grows as elements are added. Ideal for most general use cases. |
| Queue/Deque |	`std::deque<T>` | Provides O(1) insertion/removal from both ends. Good for situations where random access isn’t necessary. |
| Hash Table (unordered lookup) | `std::unordered_map<T, U>` or `std::unordered_set<T>` |	Average O(1) lookup, insertion, and deletion time complexity. Preferred for unordered key-value pairs. |
| Ordered Map/Set (sorted data) | `std::map<T, U>` or `std::set<T>` | Use when order matters (O(log N) complexity). Efficient for ordered data storage. |
| Linked List | `std::list<T>` | Provides O(1) insertion/deletion at both ends, but slower access compared to arrays or vectors. |


## 5. Memory Management & Pointers
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Raw Pointer | `T*` | Low-level pointer for accessing dynamically allocated memory. Must be manually managed (delete). |
| Pointer with Ownership | `std::unique_ptr<T>` | Provides automatic cleanup with exclusive ownership semantics. Ideal for single ownership of dynamic memory. |
| Shared Ownership of Memory | `std::shared_ptr<T>` | Allows multiple owners of a piece of memory with automatic reference counting. For shared ownership scenarios. |
| Weak Reference (to avoid cycles) | `std::weak_ptr<T>` | Prevents memory leaks by preventing cycles in `std::shared_ptr` ownership chains. |


## 6. Vectors & Large Data
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Dynamic Sized Arrays | `std::vector<T>` | Highly optimized for dynamic arrays with automatic resizing. Works well for large datasets. |
| Fixed-Size Arrays | `std::array<T, N>` | Ideal for compile-time fixed-size arrays. The data is contiguous and highly memory efficient. |
| Multi-Dimensional Arrays | `std::vector<std::vector<T>>` | For dynamically sized 2D arrays, or higher dimensions, where each row/column may grow. |
| Sparse Matrices | `std::unordered_map<std::pair<int, int>, T>` | Efficient for storing sparse data where most of the matrix is empty. Helps in memory conservation. |
| Numerical/Scientific Data | `std::array<T, N>` or `std::vector<T>` | Use `std::array` when size is fixed and known at compile time. For larger datasets, `std::vector` is more flexible. |


## 7. Misc
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Constants | `const T&` or `constexpr T` | `const` ensures immutability; `constexpr` allows the compiler to evaluate at compile time, providing potential optimization. |
| Enum Types | `enum class` | Type-safe enumerations with scoped names. Better than traditional enums (which are just ints). |
| Function Pointers/Callbacks | `std::function<T>` | Safe and flexible type for function pointers. Useful for passing and storing callable objects. |


## 8. Type Deduction and Type Safety
| **Use Case** | **Best Choice** | **Why?** |
| -------- | -------- | -------- |
| Type Deduction for Iterators | `auto&` | `auto` is the most efficient for iterators, and `auto&` ensures that large objects are passed by reference. |
| Type Deduction for Variables | `auto` | Allows the compiler to deduce the most appropriate type for a variable, saving development time. |
| Type Deduction with Function Return | `decltype` | `decltype` provides more detailed and safe type inference, especially for complex return types from functions. |