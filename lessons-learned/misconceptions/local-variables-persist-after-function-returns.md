# Misconception: Local Variables Persist After Their Function Returns

## What I Initially Thought
I thought that local variables remained intact in memory even after a function finished executing, or that they were cleared out randomly by a garbage collector.

## Why It Made Sense
When we write code, we don't write commands to explicitly delete local variables. Because we don't see any deletion syntax, it's easy to assume they remain sitting in memory, and that returning a pointer or reference to them might still work.

## Why It Was Wrong
In C++, function-local variables are allocated on the **Stack**. Their lifetime is strictly bound to the execution lifetime of their function:
1. When a function is called, its stack frame (including local variables) is allocated.
2. When the function returns, its stack frame is popped. The Stack Pointer (`SP`) moves back, marking that memory space as available/free.
3. The local variables are instantly destroyed (their destructors are called if they are objects).
4. If you attempt to access that memory address afterwards (e.g., via a returned pointer or reference), you are accessing a dangling reference. That memory will be overwritten as soon as the next function is called.

## Correct Mental Model
**Chalkboard Workspaces:** Imagine a chalkboard where each function gets a designated box to write its work. When the function is running, it writes numbers in its box. The moment the function returns, an eraser sweeps over that box (popping the stack frame). The data is gone, and the space is ready for the next function to write on.

## Example
```cpp
#include <iostream>

int* getDanglingPointer() {
    int tempVal = 100; // Allocated on getDanglingPointer's stack frame
    return &tempVal;   // TRAP: Returning address of local variable!
} // tempVal is destroyed here! Stack frame is popped.

int main() {
    int* ptr = getDanglingPointer(); 
    // ptr now points to a deallocated stack memory location!
    
    std::cout << "Value: " << *ptr << "\n"; // Might print 100 or garbage
    
    // Call another function to overwrite stack memory
    std::cout << "Doing something else...\n";
    
    std::cout << "Value again: " << *ptr << "\n"; // Will likely print garbage or crash!
    return 0;
}
```

## Lesson Learned
Never return pointers or references to local variables. Once a function returns, its stack frame is popped and its local variables are destroyed. Accessing that memory results in undefined behavior.

## Interview Reminder
If asked why returning a reference to a local variable is dangerous, state: "Local variables are allocated on the stack frame of the function. When the function returns, its stack frame is popped, destroying the variables. Returning a reference to a local variable means returning an alias to a deallocated memory address. Accessing it is a dangling reference bug and leads to undefined behavior."
