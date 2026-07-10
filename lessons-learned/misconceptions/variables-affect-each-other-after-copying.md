# Misconception: Variables Affect Each Other After Copying

## What I Initially Thought
I assumed that if I copied one variable to another (e.g., `int b = a;`), the two variables would remain connected, and modifying one would affect the other.

## Why It Made Sense
In languages like Python or JavaScript, assigning one variable to another when dealing with objects, lists, or arrays does not copy the underlying data; it copies the reference. Consequently, modifying the object through either variable affects the same memory structure. It was easy to accidentally map this reference-copy behavior onto primitive variables in C++.

## Why It Was Wrong
C++ uses value-copy semantics by default for primitive types (and user-defined objects, unless they explicitly contain custom reference pointers or custom assignment operators). When we execute `int b = a;`, C++ allocates a new block of memory specifically for `b` on the stack and copies the value of `a` into it. They have separate memory addresses.

## Correct Mental Model
**Independent Households:** Imagine two identical houses built from the same blueprint. If the owner of House B paints their front door red, the front door of House A does not change. They are completely separate physical entities, even if they looked identical at the start.

## Example
```cpp
#include <iostream>

int main() {
    int original = 100;
    int copy = original; // Allocates new memory for 'copy' and writes 100.
    
    copy = 200; // Only writes 200 to the memory space of 'copy'.
    
    std::cout << "original: " << original << "\n"; // Output: 100
    std::cout << "copy: " << copy << "\n";         // Output: 200
    return 0;
}
```

## Lesson Learned
In C++, copying primitive types creates an independent replica. Memory isolation is the default state unless references or pointers are explicitly introduced.

## Interview Reminder
If an interviewer asks you to trace C++ code involving variables and copies, emphasize that the copy is independent. If you are comparing C++ with Java/Python, highlight that C++ defaults to value semantics (allocating separate memory), whereas Python/Java default to reference semantics for objects.
