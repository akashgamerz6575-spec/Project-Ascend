# Composition vs Inheritance

Evaluating relationships between software components.

## Inheritance (`is-a`)
- **Use Case:** High reuse of base functionality with rigid type models.
- **Trade-off:** Tight coupling. Changes to the base class ripple down the entire hierarchy tree (Fragile Base Class problem).

## Composition (`has-a`)
- **Use Case:** Dynamic component construction and loose coupling.
- **Trade-off:** Boilerplate delegation methods might be required to expose component methods.
- **Verdict:** Prefer composition over inheritance. It provides greater runtime flexibility and cleaner testing separation.
