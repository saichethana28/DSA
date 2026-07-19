# Subsequences - Theory

## What is a Subsequence?

A subsequence is obtained by deleting zero or more elements without changing the relative order of the remaining elements.

Example:

```text
String: abcde

Subsequence: ace
Substring: abc
```

---

## Subsequence vs Substring

| Subsequence | Substring |
|-------------|-----------|
| Characters need not be contiguous | Characters must be contiguous |
| Order must be maintained | Contiguous by definition |
| Count = 2ⁿ | Count = n(n+1)/2 |

---

## Total Subsequences

For a string of length `n`:

- Including empty subsequence → **2ⁿ**
- Excluding empty subsequence → **2ⁿ − 1**

Reason:

Each character has two choices:

- Take
- Don't Take

---

## Generic Recursion Template

```cpp
solve(index){

    if(index == n){
        // process answer
        return;
    }

    // Take
    solve(index+1);

    // Don't Take
    solve(index+1);
}
```

---

## Common Problems

- Generate all subsequences
- Print subsequences with sum K
- Print any one subsequence with sum K
- Count subsequences with sum K
- Longest Increasing Subsequence (DP)
- Longest Common Subsequence (DP)

---

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Generate all subsequences | O(n × 2ⁿ) | O(n) |

---

## Key Takeaways

- Every character has two choices: **Take / Don't Take**.
- Base case is usually `index == n`.
- The same recursion template can be modified to **print**, **count**, or **search** subsequences.