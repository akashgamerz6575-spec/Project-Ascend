# Misconception: Pointers Automatically Work on Copied Values

## What I Initially Thought
I thought that if a variable `a` was copied from another variable `b` (e.g., `int a = b;`), and a pointer was set to point to `a` (e.g., `int *ptr = &a;`), modifying the value via `*ptr` would propagate back and modify the original `b`.

## Why It Made Sense
If one is thinking about data flows rather than physical memory locations, it is easy to assume that because `a` holds `b`'s content, they represent the same data pipeline. Under this model, a pointer to that pipeline would affect the data everywhere.

## Why It Was Wrong
Pointers deal exclusively with specific, numerical memory addresses. They do not have any semantic awareness of a variable's history or derivation.
1. When `int a = b;` executes, `a` is allocated its own unique address (e.g., `0x1111`) and receives a copy of the value from `b` (whose address is, say, `0x2222`).
2. When `int *ptr = &a;` executes, `ptr` stores the address `0x1111`.
3. When `*ptr = 200;` executes, the CPU writes `200` to the address `0x1111`.
4. The memory at `0x2222` (where `b` resides) is untouched.

## Correct Mental Model
**Photocopied Document Editing:** If you photocopy a document belonging to Friend B and put the copy in your locker (Variable A), and then you use a marker (Pointer) to cross out a line on the paper in your locker, Friend B's original document in their house (Variable B) remains completely pristine.

## Example
```cpp
#include <iostream>

int main() {
    int b = 100;
    int a = b;      // a holds a copy of b. Addresses are separate.
    int *ptr = &a;  // ptr stores the address of a.
    
    *ptr = 200;     // Modifies a's memory.
    
    std::cout << "b: " << b << "\n";   // Output: 100 (Unchanged!)
    std::cout << "a: " << a << "\n";   // Output: 200
    return 0;
}
```

## Lesson Learned
Pointers store memory addresses, not lineage. If a pointer points to a copy, it modifies the copy, leaving the original source unaffected.

## Interview Reminder
Be on the lookout for code snippets in interviews where a function parameter is passed by value (creating a copy), and then a pointer inside the function modifies the copy. Explain clearly that because of value copying, the pointer modification has no effect on the original argument in the caller's stack frame.
