# Next Greater Element II

## Problem Statement

Given a **circular integer array** `nums`, return the **Next Greater Element (NGE)** for every element. The Next Greater Element of an element is the **first greater element encountered while traversing clockwise**. If no such element exists, return `-1`.

---

## Example

### Example 1

**Input**
```text
nums = [1,2,1]
```

**Output**
```text
[2,-1,2]
```

**Explanation**

- Next greater of `1` is `2`
- `2` has no greater element
- Since the array is circular, next greater of the last `1` is `2`

---

### Example 2

**Input**
```text
nums = [1,2,3,4,3]
```

**Output**
```text
[2,3,4,-1,4]
```

---

## Understanding the Problem

- Unlike the normal Next Greater Element problem, the array is **circular**.
- After reaching the last element, traversal continues from the beginning.
- We can simulate this by traversing the array **twice** without actually duplicating it.
- The same **Monotonic Stack** pattern is used with a small modification.

---

# Optimal Approach (Monotonic Stack)

### Approach

- Traverse the array from **`2N-1` to `0`** to simulate circular traversal.
- Access the current element using **`nums[i % n]`** instead of creating a new array.
- Pop all elements **less than or equal to** the current element, as they cannot be the next greater element.
- Store the answer **only when `i < n`**. If the stack is empty, answer is `-1`; otherwise, the stack top is the next greater element. Finally, push the current element onto the stack.

## Code

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if(i < n) {
                if(st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }

            st.push(nums[i % n]);
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

- A circular array can be simulated by traversing from **`2N-1` to `0`**.
- Use **`i % n`** to access elements without creating a duplicate array.
- The **Monotonic Decreasing Stack** logic remains the same as the normal Next Greater Element problem.
- This problem is an extension of the basic NGE pattern and teaches how to handle **circular arrays** efficiently.