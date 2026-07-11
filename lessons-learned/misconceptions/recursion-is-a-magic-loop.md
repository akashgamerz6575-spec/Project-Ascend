# Misconception: Recursion is a Magic Loop

## What I Initially Thought
I thought recursion was just a "magical loop" that re-ran the same code block inside the same workspace until a condition was met.

## Why It Made Sense
Both recursion and loops (like `while` and `for`) repeat execution based on conditions. Because they solve the same kinds of problems (like printing numbers or calculating factorials), it is easy to assume they share the same execution mechanics under the hood.

## Why It Was Wrong
A loop runs within a single stack frame, updating values of existing variables.
Recursion, however, involves actual **nested function calls**:
1. Every recursive call is a separate function call.
2. The CPU allocates a brand new stack frame (workspace) for *every single call*, containing its own copy of parameters and local variables.
3. The calling stack frame remains suspended, waiting for the child function to return.
4. If a recursive function calls itself infinitely (or too deeply) without reaching a base case, it continues piling up new stack frames. 
5. Eventually, it runs out of stack memory space, causing the program to terminate with a **Stack Overflow**.

## Correct Mental Model
**Russian Nesting Dolls (Matryoshka):** If you open a doll, you find another doll inside it. Each doll represents a stack frame. You cannot close the outer doll until you have opened and closed all the inner dolls. A loop is like opening a single box, taking out an item, and putting a new one in. Recursion is piling boxes inside boxes.

## Example
```cpp
#include <iostream>

void infiniteRecursion(int count) {
    std::cout << "Call number: " << count << "\n";
    // Each call allocates another stack frame on the call stack
    infiniteRecursion(count + 1); 
} // No base case! Frames keep piling up.

int main() {
    infiniteRecursion(1);
    // Program will terminate abruptly with a "Stack Overflow" error!
    return 0;
}
```

## Lesson Learned
Recursion is memory-intensive because each nested call consumes stack space. A base case is mandatory to prevent the stack from growing indefinitely and exhausting memory.

## Interview Reminder
If asked to compare recursion and iteration, state: "Iteration runs in constant stack space because it updates variables within a single stack frame. Recursion runs in linear stack space $O(N)$ because every nested call creates a new stack frame on the call stack to store parameters and return addresses. Without a base case, this linear growth quickly leads to stack overflow."
