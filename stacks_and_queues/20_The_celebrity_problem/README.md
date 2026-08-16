# The Celebrity Problem

## Problem Statement

A celebrity is a person who:

- Knows nobody except themselves.
- Is known by everyone else.

Given `mat[i][j]`, where `1` means person `i` knows person `j`, return the celebrity's index. If no celebrity exists, return `-1`.

---

## Brute Force Approach

### Idea

For every person, check both conditions:

1. The person knows nobody except themselves.
2. Everyone else knows that person.

### Code

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        for(int i = 0; i < n; i++) {
            bool isCelebrity = true;

            for(int j = 0; j < n; j++) {
                if(i != j && (mat[i][j] == 1 || mat[j][i] == 0)) {
                    isCelebrity = false;
                    break;
                }
            }

            if(isCelebrity)
                return i;
        }

        return -1;
    }
};
```

### Complexity

- **Time:** `O(N²)`
- **Space:** `O(1)`

---

## Optimized Approach

### Idea

Use **candidate elimination** with two pointers.

For two candidates `top` and `down`:

- If `mat[top][down] == 1`, `top` knows `down`, so `top` cannot be the celebrity.
- Else if `mat[down][top] == 1`, `down` cannot be the celebrity.
- Otherwise, neither knows the other, so neither can be the celebrity.

After elimination, only one candidate remains. Then verify that candidate.

### Algorithm

1. Initialize `top = 0` and `down = n - 1`.
2. Eliminate impossible candidates until `top == down`.
3. Verify the remaining candidate:
   - Candidate knows nobody: `mat[candidate][i] == 0`
   - Everyone knows candidate: `mat[i][candidate] == 1`
4. Return the candidate if valid, otherwise `-1`.

### Code

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        int top = 0;
        int down = n - 1;

        while(top < down) {
            if(mat[top][down] == 1) {
                top++;
            }
            else if(mat[down][top] == 1) {
                down--;
            }
            else {
                top++;
                down--;
            }
        }

        if(top > down)
            return -1;

        for(int i = 0; i < n; i++) {
            if(i == top)
                continue;

            if(mat[top][i] != 0 || mat[i][top] != 1)
                return -1;
        }

        return top;
    }
};
```

### Complexity

- **Time:** `O(N)`
- **Space:** `O(1)`

---

## Key Takeaways

- Celebrity = **knows nobody + everyone knows them**.
- Use **candidate elimination** to remove impossible candidates.
- If `A` knows `B`, `A` cannot be the celebrity.
- If neither knows the other, neither can be the celebrity.
- The remaining candidate must always be **verified**.
- Pattern: **Eliminate → Candidate → Verify**.