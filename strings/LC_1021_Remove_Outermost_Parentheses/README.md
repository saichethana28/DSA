# LC 1021 - Remove Outermost Parentheses

## Problem

Given a valid parentheses string, remove the outermost parentheses from every primitive substring.

---

## Approach 1 - Find Each Primitive (My First Idea)

### Thought Process

* Keep a balance (`count`).
* `count++` for `'('` and `count--` for `')'`.
* Whenever `count == 0`, one primitive string is completed.
* Skip the first and last characters of that primitive and append the remaining characters to the answer.

### Observation

Example:

```text
(()())(())
```

Primitive 1:

```text
(()())
```

Append:

```text
()()
```

Primitive 2:

```text
(())
```

Append:

```text
()
```

### Complexity

* Time: **O(n)**
* Space: **O(1)** (excluding output)

### Drawback

I traversed each primitive again using another loop to copy its inner characters.

---

## Approach 2 - Build Answer While Traversing (Optimal)

### Key Observation

Instead of waiting until a primitive ends, decide **while traversing** whether the current parenthesis is outer or inner.

Rules:

* For `'('`

  * If `count > 0`, it is **not** an outer parenthesis → add it.
  * Then increment `count`.

* For `')'`

  * First decrement `count`.
  * If `count > 0`, it is **not** an outer parenthesis → add it.

This automatically skips the first `'('` and last `')'` of every primitive.

### Complexity

* Time: **O(n)**
* Space: **O(1)**

---

## Approach 3 - Using Stack

### Thought Process

Instead of using `count`, use a stack.

* If stack is not empty before pushing `'('`, add it.
* Push `'('`.
* Pop on `')'`.
* If stack is still not empty after popping, add `')'`.

### Complexity

* Time: **O(n)**
* Space: **O(n)**

### Observation

Works correctly, but the stack is unnecessary because only the current depth matters.

---

## Comparison

| Approach                 | Time | Space  |
| ------------------------ | ---- | ------ |
| Balance + copy primitive | O(n) | O(1)   |
| Balance while traversing | O(n) | O(1) ✅ |
| Stack                    | O(n) | O(n)   |

---

## What I Learned ⭐

* Parentheses problems often depend only on the **current depth**, not the entire stack.
* A counter can replace a stack when only the nesting level is required.
* Sometimes the best optimization is **processing characters while traversing**, instead of storing information and processing it later.
* Before using a stack, ask: **"Do I really need previous elements, or do I only need the current balance?"**
