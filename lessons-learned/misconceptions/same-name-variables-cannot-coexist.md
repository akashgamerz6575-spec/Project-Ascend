# Misconception: Variables with the Same Name Cannot Coexist

## What I Initially Thought
I assumed that variable names (identifiers) had to be unique across the entire program. Therefore, if `x` existed in `main()`, I could not declare another variable named `x` in another function, or if I did, they would conflict or refer to the same variable.

## Why It Made Sense
In basic scripting or flat scopes, declaring duplicate variable names results in "redeclaration errors". It feels like variable names are global indexes in a single list of variables.

## Why It Was Wrong
At runtime, variables are not tracked by their human-readable names; they are resolved to **physical memory addresses** (typically offsets within a stack frame).
1. **Isolated Stack Frames:** Every function call creates its own stack frame (workspace). 
2. **Name Isolation:** `x` inside `main()` resides in `main`'s stack frame. `x` inside `fun()` resides in `fun`'s stack frame.
3. **No Collision:** The compiler translates them to distinct memory locations (e.g., `StackPointer - 4` vs `StackPointer - 16`). They can coexist simultaneously while both functions are active.

## Correct Mental Model
**Different Desks:** Imagine two researchers working in different rooms of a laboratory. Both have a folder labeled "Project Alpha" (variable `x`) on their respective desks. They do not conflict because the rooms are physically separate. Changing files in room 1's "Project Alpha" folder has no impact on room 2's folder.

## Example
```cpp
#include <iostream>

void fun() {
    int x = 100; // Lives in fun()'s stack frame. Address: e.g., 0x7ffe10
    std::cout << "Inside fun():  x = " << x << " at " << &x << "\n";
}

int main() {
    int x = 50; // Lives in main()'s stack frame. Address: e.g., 0x7ffe30
    std::cout << "Before fun(): x = " << x << " at " << &x << "\n";
    
    fun(); // fun()'s frame is pushed on top of main()'s frame
    
    std::cout << "After fun():  x = " << x << " at " << &x << "\n"; // Output is still 50!
    return 0;
}
```

## Lesson Learned
Variables are scoped to their respective functions because their memory allocations are isolated inside independent stack frames. Identical names in different functions refer to separate memory locations.

## Interview Reminder
If asked to trace a program where multiple functions use the same variable name `x`, state: "The `x` declared in `fun()` is locally scoped to `fun`'s stack frame and has a unique memory address. It is completely independent of the `x` declared in `main()`'s stack frame. Modifications to `fun::x` do not affect `main::x`."
