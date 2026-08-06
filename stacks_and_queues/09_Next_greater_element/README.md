# Next Greater Element

## Problem Statement

Given an array `arr[]`, find the **Next Greater Element (NGE)** for every element. The Next Greater Element of an element is the **first greater element on its right**. If no such element exists, return `-1`.

---

## Example

### Example 1

**Input**
```text
arr = [1, 3, 2, 4]
```

**Output**
```text
[3, 4, 4, -1]
```

**Explanation**

- Next greater of `1` is `3`
- Next greater of `3` is `4`
- Next greater of `2` is `4`
- `4` has no greater element on its right

---

### Example 2

**Input**
```text
arr = [6, 8, 0, 1, 3]
```

**Output**
```text
[8, -1, 1, 3, -1]
```

---

## Understanding the Problem

- For every element, find the first greater element on its right.
- Brute force checks all elements on the right for every index.
- Since every element only depends on its right side, processing from **right to left** is more efficient.
- A **Monotonic Stack** helps find the answer in linear time.

---

# Brute Force Approach

### Approach

- Traverse every element in the array.
- For each element, scan all elements to its right.
- Return the first greater element found.
- If no greater element exists, return `-1`.

## Code

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[j] > arr[i]) {
                    ans[i] = arr[j];
                    break;
                }
            }
        }

        return ans;
    }
};
```

### Complexity Analysis

**Time Complexity:** `O(N²)`

**Space Complexity:** `O(N)` (Answer array)

---

# Optimal Approach (Monotonic Stack)

### Approach

- Traverse the array from **right to left**, so all elements on the right are already processed.
- Maintain a **monotonic decreasing stack** that stores only the useful candidates for the next greater element.
- Pop all elements **less than or equal to** the current element, as they can never be the next greater element for any future element.
- If the stack is empty, the answer is `-1`; otherwise, the stack top is the next greater element. Finally, push the current element onto the stack.

## Code

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        stack<int> st;
        vector<int> ans(arr.size());

        for(int i = arr.size() - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }
};
```

### Complexity Analysis

**Time Complexity:** `O(N)`

**Space Complexity:** `O(N)`

---

# Key Takeaways ⭐

- Traversing from **right to left** ensures all required information is already available.
- A **Monotonic Decreasing Stack** stores only useful candidates for the next greater element.
- Every element is pushed and popped at most once, giving an **O(N)** solution.
- This pattern is the foundation for problems like **Next Greater Element II, Stock Span, Daily Temperatures, Largest Rectangle in Histogram,** and **Sum of Subarray Minimums**.