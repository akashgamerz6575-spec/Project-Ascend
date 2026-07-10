/**
 * @file memory_tracing_basics.cpp
 * @brief Practical demonstration of C++ value copying, reference aliasing, and pointer address manipulation.
 * 
 * This file contains the runnable versions of the three memory-tracing exercises 
 * discussed during the learning session to help solidify correct mental models of memory.
 * 
 * Compilation:
 *   g++ -std=c++17 -Wall memory_tracing_basics.cpp -o memory_tracing_basics
 * Run:
 *   ./memory_tracing_basics
 * 
 * Domain: C++ Systems Programming / Memory Management
 */

#include <iostream>
#include <iomanip>

// Helper to print section titles
void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << title << "\n";
    std::cout << "========================================\n";
}

/**
 * Exercise 1: Value Copying & Reassignment Trace
 * 
 * Problem: Understand variable memory isolation and value copy semantics.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void runExercise1() {
    printHeader("Exercise 1: Value Copying & Reassignment");

    int a = 10;
    int b = 20;

    std::cout << "Initial values:\n";
    std::cout << "a (Address: " << &a << ") = " << a << "\n";
    std::cout << "b (Address: " << &b << ") = " << b << "\n";

    // Value Assignment (one-time copy of bits)
    a = b;

    std::cout << "\nAfter 'a = b':\n";
    std::cout << "a (Address: " << &a << ") = " << a << " (Copied from b)\n";
    std::cout << "b (Address: " << &b << ") = " << b << "\n";

    // Mutating b
    b = 30;

    std::cout << "\nAfter 'b = 30':\n";
    std::cout << "a (Address: " << &a << ") = " << a << " (Unchanged!)\n";
    std::cout << "b (Address: " << &b << ") = " << b << " (Mutated)\n";

    /*
     * Memory Walkthrough:
     * ----------------------------------------------------
     * Address       | Symbol | Type  | Value (Step 1) | Value (Step 2) | Value (Step 3)
     * ----------------------------------------------------
     * 0x7ffee1a329ac | a      | int   | 10             | 20             | 20
     * 0x7ffee1a329a8 | b      | int   | 20             | 20             | 30
     * ----------------------------------------------------
     * Note how the addresses of 'a' and 'b' are distinct and do not change.
     */
}

/**
 * Exercise 2: Reference Alias & Assignment Trace
 * 
 * Problem: Understand reference binding and mutation of the underlying target.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void runExercise2() {
    printHeader("Exercise 2: Reference Alias & Assignment");

    int original = 100;
    int &ref = original; // ref becomes a direct alias for original

    std::cout << "Initial state:\n";
    std::cout << "original (Address: " << &original << ") = " << original << "\n";
    std::cout << "ref      (Address: " << &ref      << ") = " << ref      << "\n";

    // Mutating through reference
    ref = 200;

    std::cout << "\nAfter 'ref = 200':\n";
    std::cout << "original (Address: " << &original << ") = " << original << "\n";
    std::cout << "ref      (Address: " << &ref      << ") = " << ref      << "\n";

    int other = 300;
    std::cout << "\nother    (Address: " << &other    << ") = " << other    << "\n";

    // Reassigning ref to other? (Actually, this assigns other's value to original)
    ref = other;

    std::cout << "\nAfter 'ref = other':\n";
    std::cout << "original (Address: " << &original << ") = " << original << " (Value modified via ref)\n";
    std::cout << "ref      (Address: " << &ref      << ") = " << ref      << "\n";
    std::cout << "other    (Address: " << &other    << ") = " << other    << "\n";

    // Mutating other
    other = 400;

    std::cout << "\nAfter 'other = 400':\n";
    std::cout << "original (Address: " << &original << ") = " << original << " (Unchanged!)\n";
    std::cout << "ref      (Address: " << &ref      << ") = " << ref      << " (Unchanged!)\n";
    std::cout << "other    (Address: " << &other    << ") = " << other    << "\n";

    /*
     * Memory Walkthrough:
     * ----------------------------------------------------
     * Address       | Symbol | Type  | Value (Step 1) | Value (Step 2) | Value (Step 3)
     * ----------------------------------------------------
     * 0x7ffee1a32994 | original / ref | int | 100      | 200            | 300
     * 0x7ffee1a32990 | other  | int   | -              | 300            | 400
     * ----------------------------------------------------
     * Note that 'ref' shares the exact same memory address as 'original'.
     */
}

/**
 * Exercise 3: Pointer Address & Dereference Trace
 * 
 * Problem: Understand pointer storage, reassignment of target, and dereference mutation.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void runExercise3() {
    printHeader("Exercise 3: Pointer Address & Dereferencing");

    int val = 50;
    int *ptr = &val; // ptr stores address of val

    std::cout << "Initial state:\n";
    std::cout << "val      (Address: " << &val << ") = " << val << "\n";
    std::cout << "ptr      (Value/Stored Address: " << ptr << ", Address of ptr: " << &ptr << ")\n";
    std::cout << "*ptr     (Dereferenced value) = " << *ptr << "\n";

    // Mutating via dereferenced pointer
    *ptr = 60;

    std::cout << "\nAfter '*ptr = 60':\n";
    std::cout << "val      (Address: " << &val << ") = " << val << "\n";
    std::cout << "*ptr     (Dereferenced value) = " << *ptr << "\n";

    int val2 = 70;
    std::cout << "\nval2     (Address: " << &val2 << ") = " << val2 << "\n";

    // Reassigning the pointer to point to val2
    ptr = &val2;

    std::cout << "\nAfter 'ptr = &val2':\n";
    std::cout << "val      (Address: " << &val << ") = " << val << "\n";
    std::cout << "ptr      (Value/Stored Address: " << ptr << ", Address of ptr: " << &ptr << ")\n";
    std::cout << "*ptr     (Dereferenced value) = " << *ptr << "\n";

    // Mutating via dereferenced pointer
    *ptr = 80;

    std::cout << "\nAfter '*ptr = 80':\n";
    std::cout << "val      (Address: " << &val << ") = " << val << " (Unchanged since ptr moved)\n";
    std::cout << "val2     (Address: " << &val2 << ") = " << val2 << " (Mutated via ptr)\n";
    std::cout << "*ptr     (Dereferenced value) = " << *ptr << "\n";

    /*
     * Memory Walkthrough:
     * ----------------------------------------------------
     * Address       | Symbol | Type  | Value (Step 1)     | Value (Step 2)
     * ----------------------------------------------------
     * 0x7ffee1a3297c | val    | int   | 50 -> 60           | 60
     * 0x7ffee1a32978 | ptr    | int*  | 0x7ffee1a3297c     | 0x7ffee1a32970 (address of val2)
     * 0x7ffee1a32970 | val2   | int   | 70                 | 70 -> 80
     * ----------------------------------------------------
     */
}

int main() {
    runExercise1();
    runExercise2();
    runExercise3();
    return 0;
}
