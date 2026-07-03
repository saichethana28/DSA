# LC 1614 - Maximum Nesting Depth of the Parentheses

## Problem

Given a **valid parentheses string (VPS)**, return its **maximum nesting depth**.

The nesting depth is the maximum number of open parentheses surrounding any character in the expression.

---

## Key Observation 💡

Each opening parenthesis `'('` increases the current nesting depth.

Each closing parenthesis `')'` decreases the current nesting depth.

Therefore, while traversing the string:

* Increment the depth when encountering `'('`.
* Update the maximum depth.
* Decrement the depth when encountering `')'`.

---

## Approach

### Step 1

Initialize:

* `count` → current nesting depth.
* `maxi` → maximum nesting depth encountered.

### Step 2

Traverse the string character by character.

* If the character is `'('`

  * Increase `count`.
  * Update `maxi`.

* If the character is `')'`

  * Decrease `count`.

Ignore digits and arithmetic operators since they do not affect the nesting depth.

---

## Example

**Input**

```text id="6gcg39"
"(1+(2*3)+((8)/4))+1"
```

Traversal:

```text id="1gk2qs"
(  -> depth = 1
(  -> depth = 2
(  -> depth = 3
)  -> depth = 2
)  -> depth = 1
)  -> depth = 0
```

Maximum depth:

```text id="0bmwph"
3
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## What I Learned ⭐

* Parentheses depth can be tracked using a simple counter.
* Since the string is guaranteed to be a valid parentheses string, the counter never becomes negative.
* A stack is unnecessary for this problem because only the current depth is required.
* Whenever only the nesting level is needed, a counter is usually sufficient and more space-efficient than a stack.
