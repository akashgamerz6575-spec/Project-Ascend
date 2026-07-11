# Functions and Parameter Passing in C++

Functions are the primary building blocks of modular programming in C++. At the memory level, a function represents a self-contained execution workspace (stack frame) containing its own instructions, parameters, and local variables.

---

## 1. Function Definition & Declaration

In C++, a function must be declared (or defined) before it is called.

*   **Declaration (Prototype):** Informs the compiler about the function's name, return type, and parameter types.
*   **Definition:** Contains the actual body of code to execute.

```cpp
// Function Declaration
int calculateSum(int a, int b);

// Function Definition
int calculateSum(int a, int b) {
    int sum = a + b; // local variable
    return sum;
}
```

---

## 2. Function Call & Execution Flow

When a function call is executed (e.g., `calculateSum(x, y)`):
1.  **Arguments Evaluation:** The caller evaluates the argument expressions.
2.  **Stack Frame Allocation:** The CPU allocates a new stack frame for the called function.
3.  **Parameter Initialization:** The parameters (`a` and `b`) are allocated in the new stack frame and initialized with the argument values.
4.  **Control Transfer:** The CPU jumps to the memory address of the function's first instruction. The return address (where to resume in the caller) is pushed onto the stack.
5.  **Execution:** The function body executes.
6.  **Return & Cleanup:** The return value is copied back, the stack frame is popped (destroying local variables), and control jumps back to the return address.

---

## 3. Local Variables vs. Function Parameters

*   **Function Parameters:** Variables declared in the function's parameter list. They are initialized using the arguments provided in the function call.
*   **Local Variables:** Variables declared inside the function body. They are only created when execution reaches their declaration and are destroyed when the function exits.

Both parameters and local variables live in the function's stack frame.

---

## 4. Parameter Passing Mechanics

C++ supports two main parameter passing mechanisms: **Pass by Value** and **Pass by Reference**.

### Pass by Value
*   **Behavior:** The compiler allocates a brand new memory block for the parameter and copies the argument's *value* into it.
*   **Memory layout:** The parameter and the argument reside at completely separate addresses.
*   **Side Effects:** Changes to the parameter inside the function have **no effect** on the caller's variable.
*   **Use Case:** Small primitive types (e.g., `int`, `char`, `double`).

```cpp
void increment(int x) { // Pass by value
    x = x + 1; // Only changes local copy x
}
```

### Pass by Reference
*   **Behavior:** The parameter becomes an **alias** (reference) for the caller's argument.
*   **Memory layout:** No new integer is created; the parameter name shares the exact same memory address as the argument.
*   **Side Effects:** Any changes made to the parameter inside the function **immediately modify** the caller's original variable.
*   **Use Case:** Large objects (to avoid copy overhead) or when the function needs to modify the caller's arguments.

```cpp
void increment(int &x) { // Pass by reference
    x = x + 1; // Directly changes the caller's variable
}
```

---

## 5. Return Flow

When a function executes a `return` statement:
1.  **Value Copying:** If the return type is not `void`, the returned value is copied into a temporary register or a designated space in the caller's stack frame.
2.  **Stack Popping:** The function's stack frame is popped off the call stack. All local variables and parameters are destroyed.
3.  **Control Return:** The CPU reads the return address from the stack and jumps back to that location in the caller function to resume execution.

---

## 6. Common Mistakes

1.  **Returning a Reference to a Local Variable:**
    *   *Mistake:* Returning a reference (or pointer) to a variable declared inside the function.
    *   *Consequence:* The local variable is destroyed when the stack frame is popped. The caller receives a reference to deallocated stack memory, causing undefined behavior.
    *   *Example:*
        ```cpp
        int& getLocalRef() {
            int x = 10;
            return x; // Warning: reference to local variable 'x' returned
        }
        ```

2.  **Confusing Pass by Value with Pass by Reference:**
    *   *Mistake:* Forgetting the `&` symbol when direct modification of the caller's variable is intended.
    *   *Consequence:* The variable is copied instead, and modifications inside the function are lost.

3.  **Unnecessary Copies of Large Objects:**
    *   *Mistake:* Passing large objects (like `std::vector` or custom structs) by value.
    *   *Consequence:* High CPU and memory overhead due to deep-copying. Use `const T&` instead.

---

## 7. Interview Notes

*   **What is the default parameter passing in C++?**
    *   C++ defaults to pass-by-value for all types.
*   **Does a reference parameter occupy memory on the stack?**
    *   Semantically, a reference is an alias and does not occupy memory. However, under the hood, the compiler implements reference parameters by passing the address (pointer) of the original variable, which occupies 8 bytes (on 64-bit systems).
*   **Why should we use `const T&`?**
    *   `const T&` (const reference) allows passing a large object without copying it (highly efficient) while preventing the function from modifying its contents (safe).
