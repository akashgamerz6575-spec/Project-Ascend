# Misconception: Scope is Just a Set of Memorized Syntactic Rules

## What I Initially Thought
I thought scope was just a set of compile-time syntax rules dictated by curly braces `{}` that we must memorize (e.g., "variables declared inside a block cannot be accessed outside it").

## Why It Made Sense
Introductory courses and syntax diagrams teach scope by pointing to braces. When writing code, the compiler stops us with errors like "identifier not found" if we reference a variable outside its block, making it look like a strict, arbitrary grammar rule.

## Why It Was Wrong
Scope is the high-level language representation of a physical runtime reality: **stack memory allocation**. When a function is called, the CPU allocates a dedicated region of stack memory (a stack frame or workspace) for it. All local variables declared in that function reside in this stack frame. When the function finishes and returns, its stack frame is popped off and the memory is reclaimed. 
Therefore, you cannot access a local variable from another function because *that variable's memory space does not exist* in the currently executing stack frame, or it has already been destroyed.

## Correct Mental Model
**Workspaces:** Imagine a building with temporary workspaces. When Team A starts a project, they get a desk (stack frame) and put their tools (local variables) on it. When Team A finishes, their desk is completely cleared off. If Team B comes in, they cannot use Team A's tools because those tools are physically gone. Scope is the physical presence or absence of these workspaces in RAM.

## Example
```cpp
#include <iostream>

void secondFunction() {
    int localVal = 42; // Allocated on secondFunction's stack frame
    std::cout << "Local value: " << localVal << "\n";
} // secondFunction's stack frame is popped here; localVal is destroyed!

int main() {
    secondFunction();
    
    // TRAP: This will fail to compile!
    // std::cout << localVal << "\n"; 
    // Error: 'localVal' was not declared in this scope.
    // Why? Because localVal's memory block no longer exists.
    
    return 0;
}
```

## Lesson Learned
Never memorize scope as a set of text-based constraints. Understand scope through **memory ownership**. A variable's scope is exactly equal to the lifetime of the stack frame that owns it.

## Interview Reminder
If asked about scope, explain it through stack mechanics: "Scope is C++'s compiler-enforced boundary for variable access, but at runtime, it represents stack frame lifetime. Local variables reside in their function's stack frame. When the function execution ends, the stack frame is popped, reclaiming the memory and destroying the local variables, making them physically inaccessible."
