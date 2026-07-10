# SOLID Design Principles

SOLID is a mnemonic acronym for five design principles intended to make software designs more understandable, flexible, and maintainable.

## 1. Single Responsibility Principle (SRP)
- **Definition:** A class or module should have one, and only one, reason to change.
- **Trade-off:** Increases the number of files and abstractions, but isolates changes.

## 2. Open-Closed Principle (OCP)
- **Definition:** Software entities should be open for extension, but closed for modification.
- **Trade-off:** Requires abstract base classes or interfaces, which adds initial design overhead.

## 3. Liskov Substitution Principle (LSP)
- **Definition:** Subtypes must be substitutable for their base types without altering correctness.
- **Trade-off:** Constrains inheritance depth and hierarchy models.

## 4. Interface Segregation Principle (ISP)
- **Definition:** Clients should not be forced to depend on methods they do not use.
- **Trade-off:** Results in many fine-grained interfaces, requiring complex inheritance charts.

## 5. Dependency Inversion Principle (DIP)
- **Definition:** High-level modules should not import anything from low-level modules. Both should depend on abstractions.
- **Trade-off:** Inversion of Control (IoC) containers can make tracking runtime behavior harder.
