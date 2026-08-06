# Next Smaller Element

## Problem Statement

Given an integer array `arr[]`, find the **Next Smaller Element (NSE)** for every element. The Next Smaller Element of an element is the **first smaller element on its right**. If no such element exists, return `-1`.

---

## Example

### Example 1

**Input**
```text
arr = [4, 8, 5, 2, 25]
```

**Output**
```text
[2, 5, 2, -1, -1]
```

**Explanation**

- Next smaller of `4` is `2`
- Next smaller of `8` is `5`
- Next smaller of `5` is `2`
- `2` has no smaller element on its right
- `25` has no smaller element on its right

---

### Example 2

**Input**
```text
arr = [13, 7, 6, 12]
```

**Output**
```text
[7, 6, -1, -1]
```

---

## Understanding the Problem

- For every element, find the first smaller element on its right.
- Brute force checks every element on the right for each index.
- Since every element only depends on its right side, processing from **right to left** is more efficient.
- A **Monotonic Increasing Stack** helps solve the problem in linear time.

---

# Brute Force Approach

### Approach

- Traverse every element in the array.
- For each element, scan all elements to its right.
- Return the first smaller element found.
- If no smaller element exists, return `-1`.

## Code

```cpp
class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[i]) {
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

- Traverse the array from **right to left**.
- Maintain a **monotonic increasing stack**.
- Pop all elements **greater than or equal to** the current element.
- If the stack is empty, answer is `-1`; otherwise, stack top is the next smaller element. Finally, push the current element.

## Code

```cpp
class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {

        stack<int> st;
        vector<int> ans(arr.size());

        for(int i = arr.size() - 1; i >= 0; i--) {

            while(!st.empty() && st.top() >= arr[i]) {
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

- Traverse from **right to left** so all required information is already available.
- A **Monotonic Increasing Stack** stores only useful candidates for the next smaller element.
- Every element is pushed and popped at most once, giving an **O(N)** solution.
- This pattern is the opposite of **Next Greater Element** and forms the basis for problems like **Sum of Subarray Minimums** and **Largest Rectangle in Histogram**.