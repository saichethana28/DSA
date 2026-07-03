# LC 13 - Roman to Integer

## Problem

Given a Roman numeral, convert it into its corresponding integer value.

Roman numerals normally follow the **largest to smallest** order, except for six special subtraction cases:

```text
IV = 4     IX = 9
XL = 40    XC = 90
CD = 400   CM = 900
```

---

## My Initial Thought

Initially, I tried handling all six subtraction cases individually using multiple `if-else` conditions.

For example:

* `IV`
* `IX`
* `XL`
* `XC`
* `CD`
* `CM`

Although this works, it makes the code lengthy and harder to maintain.

---

## Key Observation 💡

Instead of checking six different cases, observe the following rule:

* If the current Roman numeral is **greater than or equal to** the next numeral, **add** its value.
* If the current Roman numeral is **smaller** than the next numeral, **subtract** its value.

This single observation automatically handles all six subtraction cases.

---

## Approach

### Step 1

Create a hash map storing the value of each Roman symbol.

### Step 2

Initialize the answer with the value of the **last character**.

### Step 3

Traverse the string from **right to left**.

* If the current value is greater than or equal to the next value:

  * Add it to the answer.

* Otherwise:

  * Subtract it from the answer.

### Step 4

Return the final answer.

---

## Example

**Input**

```text
s = "MCMXCIV"
```

Traversal

```text
Start with V = 5

I < V  → subtract 1  → 4
C > I  → add 100     → 104
X < C  → subtract 10 → 94
M > X  → add 1000    → 1094
C < M  → subtract100 → 994
M > C  → add1000     → 1994
```

Output

```text
1994
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

(The hash map always contains only seven Roman symbols.)

---

## What I Learned ⭐

* Instead of handling every special case separately, look for a general pattern.
* Traversing from right to left makes the subtraction rule very simple.
* Comparing adjacent values is enough to solve all Roman numeral cases.
* A single comparison replaces multiple `if-else` conditions, making the solution shorter and easier to understand.
