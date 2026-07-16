# Reverse a Stack using Recursion

## Problem

Given a stack of integers, reverse the stack **using only recursion** and standard stack operations (`push`, `pop`, `top`, `empty`).

No loops or additional data structures are allowed.

---

# Brute Force Approach

## Idea

Use an auxiliary stack to store all elements.

1. Pop every element from the original stack.
2. Push them into another stack.
3. The second stack becomes the reversed stack.

> **Note:** This approach uses extra space and is **not allowed** in this problem.

### Complexity

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

### Code

```cpp
// Uses an extra stack (Not allowed)
```

---

# Optimal Approach (Recursion)

## Key Observation

- The recursion call stack itself acts as the temporary storage.
- Recursively remove every element until the stack becomes empty.
- While recursion backtracks, insert each removed element at the **bottom** of the stack.
- A helper function `insertAtBottom()` is used to place an element at the bottom recursively.

### Algorithm

#### reverseStack()

1. If the stack is empty, return.
2. Pop the top element.
3. Recursively reverse the remaining stack.
4. Insert the popped element at the bottom.

#### insertAtBottom()

1. If the stack is empty:
   - Push the current element.
   - Return.
2. Pop the top element.
3. Recursively insert the current element at the bottom.
4. Push the removed element back.

### Complexity

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(N)` (Recursion Stack)

### Code

```cpp
class Solution {
public:

    void insertAtBottom(stack<int>& st, int x) {

        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    void reverseStack(stack<int>& st) {

        if (st.empty())
            return;

        int temp = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, temp);
    }
};
```

---

# Interview Discussion

- The recursion stack replaces the need for an auxiliary stack.
- Break the problem into two recursive functions:
  - `reverseStack()` → Reverses the remaining stack.
  - `insertAtBottom()` → Places an element at the bottom.
- This follows the common recursion pattern: **Pop → Recurse → Restore**.

---

# What I Learned ⭐

- Recursion can replace an explicit auxiliary stack.
- Helper recursive functions simplify complex recursive problems.
- Inserting an element at the bottom of a stack can be done recursively.
- Many stack recursion problems follow the pattern: **Pop → Recurse → Restore**.
- Backtracking is useful for rebuilding data structures after recursive calls.