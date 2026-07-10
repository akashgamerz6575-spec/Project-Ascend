# Clean Code Standards

Practical guidelines for maintaining clean, readable, and professional codebases.

## 1. Meaningful Names
- Class names should be nouns (e.g., `UserAuthenticator`, `TelemetryCollector`).
- Method names should be verbs (e.g., `authenticateUser`, `collectData`).
- Avoid abbreviations (e.g., use `customerRecord` instead of `custRec`).

## 2. Functions
- Small: Functions should focus on doing one thing.
- Minimal Arguments: Ideally, zero to two arguments. Extract arguments into distinct configuration objects if they exceed three.

## 3. Comments
- Code should explain itself. Use comments only to explain "why" a certain decision was made, not "what" the code is doing.
