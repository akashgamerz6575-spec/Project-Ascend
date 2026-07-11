# Misconception: Pass by Value Modifies the Original Variable

## What I Initially Thought
I thought that passing a variable as an argument to a function allowed the function to directly manipulate the original variable, meaning any modifications made inside the function would persist in the caller.

## Why It Made Sense
It is easy to assume that when we pass `x` into `change(x)`, the label `x` inside the function refers directly to the same `x` in `main()`. In some languages, or due to syntax simplification, it feels like the variable itself is passed.

## Why It Was Wrong
C++ uses **Value Semantics** by default. When a function is called with arguments passed by value:
1. The CPU allocates memory for the parameters within the function's own new stack frame.
2. The values of the arguments in the caller are copied into these new parameter boxes.
3. The function operates exclusively on these local copies.
4. When the function returns, its stack frame is popped, destroying these copy variables. The original variables in the caller's stack frame remain completely untouched.

## Correct Mental Model
**Photocopying:** Imagine you have a sheet of paper with a drawing on it (the original variable). You make a photocopy of it (pass by value) and hand it to a classmate. If the classmate draws a red circle on their copy (modifying the parameter), your original paper remains clean. They only changed their copy, which they throw away when they finish (popping the stack frame).

## Example
```cpp
#include <iostream>

void modifyValue(int copyX) { // copyX is a brand new variable in modifyValue's stack frame
    copyX = 999;             // Only modifies the copy
} // copyX is destroyed here!

int main() {
    int originalX = 5;
    modifyValue(originalX); // Copies 5 into modifyValue's stack frame
    
    std::cout << "Original Value: " << originalX << "\n"; // Output is still 5!
    return 0;
}
```

## Lesson Learned
Passing an argument by value isolates the caller's variable from the function. The compiler creates a completely new memory cell for the parameter, and changes to it have zero side effects on the original variable.

## Interview Reminder
If asked to trace value-passing, state: "Since the function signature specifies `modifyValue(int copyX)`, it is a pass-by-value call. The parameter `copyX` is allocated in `modifyValue`'s stack frame, and the compiler copies the value of `originalX` into it. Modifications to `copyX` are local to this frame and do not affect `originalX` in `main`'s frame."
