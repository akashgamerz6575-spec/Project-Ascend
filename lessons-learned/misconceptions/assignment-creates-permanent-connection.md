# Misconception: Assignment Creates a Permanent Connection between Variables

## What I Initially Thought
I thought that writing `a = b` establishes a persistent relationship or link between variable `a` and variable `b`, such that any future changes to `b` would automatically update `a`.

## Why It Made Sense
In mathematics, writing $a = b$ represents an identity or equation that remains true. In some high-level reactive programming environments, variables can be bound together. Thus, it was easy to assume that assignment created a permanent reference pipeline between the two symbols.

## Why It Was Wrong
C++ operates close to the hardware. When `a = b;` is compiled, it generates machine code that copies the raw bits stored in the memory address of `b` into the memory address of `a`. This is a one-time, instantaneous copy operation. Once the instruction completes, the CPU has no record or track of where the bits in `a` came from. They are completely independent memory cells.

## Correct Mental Model
**The Photocopy Analogy:** Imagine you have two folders, Folder A and Folder B. When you run `a = b;`, you take the paper in Folder B, photocopy it, and place the copy in Folder A. Mutating Folder B later by adding more text does not change the physical paper inside Folder A. They have separate identities and separate physical locations.

## Example
```cpp
#include <iostream>

int main() {
    int a = 10;
    int b = 20;
    
    a = b; // a now holds 20.
    b = 30; // b is mutated to 30.
    
    std::cout << "a: " << a << "\n"; // Output: 20
    std::cout << "b: " << b << "\n"; // Output: 30
    return 0;
}
```

## Lesson Learned
Variables in C++ possess distinct, isolated memory addresses by default. Assignment copies data at a single point in time and does not create an ongoing relationship.

## Interview Reminder
During dry-runs of code in technical interviews, maintain a dry-run table mapping variables to distinct, hypothetical memory addresses. Never propagate changes from one variable to another unless they explicitly share memory through pointers or references.
