# Remove K Digits

## Problem Statement

Given a string `num` representing a non-negative integer and an integer `k`, remove exactly `k` digits from `num` so that the resulting number is the smallest possible.

Return the resulting number as a string.

### Example

Input: `num = "1432219", k = 3`

Output: `"1219"`

Explanation:

Remove `4`, `3`, and `2` to obtain the smallest possible number:

`1432219 → 1219`

---

## Approach — Monotonic Stack

### Key Observation

To make the number as small as possible, whenever a smaller digit comes after a larger digit, remove the larger digit.

For example:

`4 3`

Since `4 > 3`, removing `4` makes the number smaller.

### Algorithm

1. Traverse the digits from left to right.
2. Maintain a monotonic increasing stack.
3. While the stack is not empty, `k > 0`, and `stack.top() > current digit`, pop the stack.
4. Decrease `k` after every removal.
5. Push the current digit into the stack.
6. If `k` is still greater than `0` after traversal, remove digits from the end of the stack.
7. Convert the stack into the answer.
8. Remove leading zeros.
9. If nothing remains, return `"0"`.

### Why Remove From the End?

If `k` is still remaining after processing all digits, the number is already in non-decreasing order.

Removing digits from the end preserves the smaller and more significant prefix.

Example:

`12345`, `k = 2`

Remove:

`5 → 4`

Result:

`123`

---

## Code

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char c : num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }

            st.push(c);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;

        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        if(i == ans.size()) {
            return "0";
        }

        return ans.substr(i);
    }
};

## Complexity

- Time: `O(N)`
- Space: `O(N)`

Each digit is pushed and popped at most once.

---

## Key Takeaways

- Use a monotonic increasing stack.
- If `stack.top() > current digit`, remove the larger previous digit.
- Use `while`, not `if`, because one digit can cause multiple removals.
- If `k` remains after traversal, remove digits from the end.
- Remove leading zeros from the final answer.
- If all digits are removed or only zeros remain, return `"0"`.