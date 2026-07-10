# Interview Prep: C++ Memory & Reference Fundamentals

Comprehensive questions, model answers, and traps to study for technical interviews.

---

## Question 1: References vs. Pointers
**Question:** Compare pointers and references in C++. What are their key differences in memory usage, safety, and operational syntax?

### Model Answer
At a high level:
1. **Definition & Binding:** A reference is a syntactically transparent alias for an existing object and must be initialized upon declaration. A pointer is an independent variable that holds a memory address and can be declared without immediate initialization (or initialized to `nullptr`).
2. **Reseating:** References are permanently bound to their initial target; they cannot be modified to refer to a different object after creation. Pointers can be reassigned to hold different addresses at any time.
3. **Nullability:** References cannot be null (they must refer to a valid object). Pointers can be null (`nullptr`), which means they require safety checks before dereferencing to prevent Segmentation Faults.
4. **Memory Allocation:** Semantically, references do not occupy their own addressable memory; taking their address (`&ref`) yields the target's address. Pointers are separate variables that occupy 8 bytes of space (on 64-bit systems) to store address values.

---

## Question 2: The Reference Assignment Trap
**Question:** What does the following code output, and why?
```cpp
int x = 10;
int y = 20;
int &ref = x;
ref = y;
y = 30;
std::cout << x << " " << y << " " << ref;
```

### Model Answer
**Output:** `20 30 20`

### Explanation
1. `int &ref = x;` binds `ref` as an alias to the memory address of `x`.
2. `ref = y;` does **not** rebind `ref` to alias `y`. Instead, because `ref` is a nickname for `x`, it translates directly to the assignment `x = y;`. The value of `y` (20) is copied into `x`'s memory address.
3. `y = 30;` mutates the value at `y`'s address to 30. This has no effect on `x`'s address.
4. When printed, `x` holds 20, `y` holds 30, and `ref` (being an alias of `x`) evaluates to `x`'s value, which is 20.

---

## Question 3: Overloading the Ampersand (`&`) Symbol
**Question:** Explain the different meanings of the `&` symbol in C++ based on syntactic context, and identify which of the following lines will compile successfully:
```cpp
int val = 50;
int &ref = val;  // Line 1
int *ptr = &val; // Line 2
int &ref2 = &val; // Line 3
```

### Model Answer
The `&` symbol is overloaded in C++:
* In type declarations (e.g., `Type &name`), it declares a reference type.
* In expressions prefixing a variable (e.g., `&val`), it is the unary address-of operator.

**Line Compile Check:**
* **Line 1 compiles:** `int &ref = val;` declares a reference `ref` bound to the lvalue `val`.
* **Line 2 compiles:** `int *ptr = &val;` retrieves the address of `val` (type `int*`) and stores it in the pointer `ptr`.
* **Line 3 fails to compile:** `int &ref2 = &val;` tries to initialize a reference to `int` (`int&`) using the address of `val` (`int*`). A reference to `int` must be initialized with an lvalue of type `int`, not a pointer address of type `int*`.

---

## Question 4: Pointers to Copies
**Question:** Explain what is wrong with the following code snippet and what its output is:
```cpp
int original = 15;
int copy = original;
int *ptr = &copy;
*ptr = 25;
std::cout << original << " " << copy;
```

### Model Answer
**Output:** `15 25`

### Explanation
1. `int copy = original;` allocates independent memory for `copy` and copies the value 15. The variables `original` and `copy` have completely disjoint memory locations.
2. `int *ptr = &copy;` points the pointer to the address of `copy`.
3. `*ptr = 25;` dereferences the pointer and writes 25 directly into the address of `copy`.
4. The memory block of `original` is completely untouched because the copy operation broke any connection to the original variable, and the pointer only referenced the copy.

---

## Follow-up Questions for Study
* *What is the difference between a `const pointer` and a `pointer to const`?*
* *How do references behave when passed to functions under the hood?*
* *Why can you return a pointer to heap memory, but returning a reference to a local stack variable is dangerous?*

---

## Common Traps to Avoid
* **Reseating Myth:** Never write code assuming you can change what a reference refers to.
* **Implicit Copies:** Be careful with function arguments. Passing by value creates a copy. Taking pointers to those parameters inside the function will modify only local copies.
* **Dangling References:** Returning a reference to a local variable that goes out of scope will lead to undefined behavior (reading/writing garbage memory).
