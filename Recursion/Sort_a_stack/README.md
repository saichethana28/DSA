# Sort a Stack using Recursion

## Problem

Given a stack of integers, sort the stack in **descending order** using **only recursion** and standard stack operations (`push`, `pop`, `top`, `empty`).

The largest element should be at the **top** of the stack.

---

# Brute Force Approach

## Idea

Use an auxiliary stack to maintain the elements in sorted order.

For each element in the original stack:

- Pop the element.
- Insert it into the correct position in the auxiliary stack.
- Move elements back if required.

### Algorithm

1. Create an empty auxiliary stack.
2. Pop elements from the original stack one by one.
3. Insert each element into its correct position in the auxiliary stack.
4. Transfer the elements back if needed.

### Complexity

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(N)` (Auxiliary Stack)

### Code

```cpp
// Uses an extra stack (Not allowed in this problem)
```

---

# Optimal Approach (Recursion)

## Key Observation

- The recursion call stack itself can act as the temporary storage.
- First, recursively remove every element until the stack becomes empty.
- While recursion backtracks, insert each element into its correct position.
- To insert an element into a sorted stack, recursively remove larger elements, insert the current element, and restore the removed elements.

### Algorithm

#### sortStack()

1. If the stack is empty, return.
2. Pop the top element.
3. Recursively sort the remaining stack.
4. Insert the popped element into its correct position.

#### insert()

1. If the stack is empty or the top element is less than or equal to the current element:
   - Push the current element.
   - Return.
2. Pop the top element.
3. Recursively insert the current element.
4. Push the removed element back.

### Complexity

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(N)` (Recursion Stack)

### Code

```cpp
class Solution {
public:

    void insert(stack<int>& st, int x) {

        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insert(st, x);

        st.push(temp);
    }

    void sortStack(stack<int>& st) {

        if (st.empty())
            return;

        int temp = st.top();
        st.pop();

        sortStack(st);

        insert(st, temp);
    }
};
```

---

# Interview Discussion

- The recursion call stack replaces the need for an auxiliary stack.
- The problem is divided into two recursive functions:
  - `sortStack()` → Sorts the remaining stack.
  - `insert()` → Inserts one element into a sorted stack.
- This is a classic example of solving a problem during the **backtracking phase** of recursion.

---

# What I Learned ⭐

- Recursion can replace an explicit auxiliary stack.
- Break complex recursion problems into smaller recursive functions.
- The pattern **Pop → Recurse → Insert/Restore** appears in many stack recursion problems.
- Backtracking is useful for rebuilding data structures after recursive calls.
- Separating responsibilities (`sortStack()` and `insert()`) makes recursive solutions much cleaner.