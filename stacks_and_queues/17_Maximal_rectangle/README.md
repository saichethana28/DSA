# Maximal Rectangle

## Problem Statement

Given a `m x n` binary matrix filled with `0`s and `1`s, find the largest rectangle containing only `1`s and return its area.

### Example

Input:

`matrix = [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]`

Output:

`6`

### What I Understand

The problem can be converted into multiple **Largest Rectangle in Histogram** problems.

For every row, maintain the height of consecutive `1`s in each column.

Each row then becomes a histogram, and we can apply the **Largest Rectangle in Histogram** monotonic stack approach.

---

## Approach — Histogram + Monotonic Stack

### Algorithm

1. Create a `heights` array of size `m`.
2. Traverse the matrix row by row.
3. If `matrix[i][j] == '1'`, increase `heights[j]`.
4. If `matrix[i][j] == '0'`, reset `heights[j] = 0`.
5. Treat `heights` as a histogram.
6. Find the largest rectangle in the histogram using a monotonic stack.
7. Update the maximum area for every row.

### Example

For the matrix:

`1 0 1 1 1`  
`1 0 1 1 1`  
`1 1 1 1 1`

The histogram heights become:

`1 0 1 1 1`

`2 0 2 2 2`

`3 1 3 3 3`

For the third row:

`[3,1,3,3,3]`

The last three columns form a rectangle:

`height = 3`

`width = 3`

`area = 3 × 3 = 9`

---

## Code

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<int> heights(m, 0);

        for(int i = 0; i < n; i++) {

            // Build histogram heights for current row
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Largest Rectangle in Histogram
            stack<int> st;

            for(int j = 0; j < m; j++) {

                while(!st.empty() &&
                      heights[st.top()] >= heights[j]) {

                    int h = heights[st.top()];
                    st.pop();

                    if(st.empty()) {
                        int area = h * j;
                        ans = max(ans, area);
                    } else {
                        int area = h * (j - st.top() - 1);
                        ans = max(ans, area);
                    }
                }

                st.push(j);
            }

            // Process remaining elements
            while(!st.empty()) {

                int h = heights[st.top()];
                st.pop();

                if(st.empty()) {
                    int area = h * m;
                    ans = max(ans, area);
                } else {
                    int area = h * (m - st.top() - 1);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};
```

---

## Complexity

- **Time:** `O(N × M)`
- **Space:** `O(M)`

For every row, the histogram is processed in `O(M)` using the monotonic stack.

---

## Key Takeaways

- Convert every matrix row into a histogram of consecutive `1`s.
- Reuse the **Largest Rectangle in Histogram** pattern.
- `heights[j]++` when the current cell is `1`.
- Reset `heights[j] = 0` when the current cell is `0`.
- Apply the single monotonic stack approach to every histogram.
- **2D Matrix → 1D Histogram → Largest Rectangle → Monotonic Stack**.