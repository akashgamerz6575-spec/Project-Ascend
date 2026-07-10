# Concurrency Fundamentals

Concepts, patterns, and pitfalls of parallel execution.

## 1. Concurrency vs Parallelism
- **Concurrency:** Managing multiple tasks simultaneously (overlapping execution context).
- **Parallelism:** Executing multiple tasks at the exact same physical time (multi-core hardware utilization).

## 2. Shared Memory & Thread Safety
- **Race Condition:** Two or more threads accessing shared memory concurrently where at least one thread performs a write operation.
- **Primitives:** Utilize Mutexes, Semaphores, and Atomic variables to guarantee thread safety.
- **Deadlock:** Occurs when two or more threads are blocked forever, each waiting for the other to release locks. Prevent by establishing strict lock acquisition order.
