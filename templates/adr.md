# Architectural Decision Record: [Title of Decision]

- **Status:** [Proposed / Accepted / Rejected / Superseded]
- **Date:** [YYYY-MM-DD]
- **Decider(s):** Akash V
- **Context Link:** [Associated Issue, PR, or Project Doc]

---

## 1. Context & Problem Statement
Describe the architectural challenge, constraints, and requirements. What choices do we face?

---

## 2. Decision & Rationale
Which tool, library, or pattern was selected? Why was it selected over alternatives?

---

## 3. Trade-off Evaluation

### Option 1: Selected Choice (e.g., PostgreSQL)
- **Advantages:** (Relational guarantees, extensibility, indexing tools).
- **Disadvantages/Trade-offs:** (Horizontal scale limits, configuration complexity, overhead).

### Option 2: Alternative (e.g., MongoDB)
- **Advantages:** (Schemaless, horizontal scale, JSON natively supported).
- **Disadvantages/Trade-offs:** (Lack of strict relational constraints, manual joins).

---

## 4. Consequences
- **Positive Outcomes:** What capabilities are now unlocked?
- **Negative Outcomes/Overhead:** What technical debt or configuration load is introduced?
