# 79. Word Search

## 📝 Problem

Given an `m × n` board of characters and a string `word`, determine if the word exists in the grid. The word can be formed by moving **up, down, left, or right**, and each cell can be used **only once** in a path.

### Example

```text
Input:
board = [["A","B","C","E"],
         ["S","F","C","S"],
         ["A","D","E","E"]]

word = "ABCCED"

Output:
true
```

---

## ⚡ Optimal Approach

### Key Observations

- We can start searching from **any cell** in the board.
- If the current cell doesn't match the required character, stop exploring that path immediately.
- Once a cell is used in the current path, it cannot be reused until we backtrack.
- We only need **one valid path**, so combine recursive calls using `||`.

### Approach

- Iterate through every cell of the board as a possible starting position.
- Perform DFS only if the current cell matches the first character.
- Mark the current cell as visited by replacing it with `'#'`.
- Explore all four directions recursively.
- Restore the original character while backtracking and return whether any path matched the word.

### Complexity

**Time:** `O(M × N × 3^K)`

**Space:** `O(K)`

Where:
- `M` = Number of rows
- `N` = Number of columns
- `K` = Length of the word

**Reason:**
We start DFS from every cell (`M × N`). After the first move, each recursive call explores at most **3** new directions since we cannot revisit the previous cell. The recursion depth is at most `K`.

### Code

```cpp
class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word, int i, int r, int c) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') {
            return false;
        }

        if (board[r][c] != word[i]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool result = solve(board, word, i + 1, r + 1, c) ||
                      solve(board, word, i + 1, r - 1, c) ||
                      solve(board, word, i + 1, r, c + 1) ||
                      solve(board, word, i + 1, r, c - 1);

        board[r][c] = temp;

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```

---

## 💡 Interview Notes

- We **must try every cell** as a starting point because the starting character can appear anywhere.
- Mark the current cell as visited before exploring neighbours and **restore it after recursion** (Backtracking).
- Use `||` because the problem asks whether **at least one path exists**.
- The restore step **must happen before returning**; otherwise, the board remains modified for other paths.
- The DFS function checks whether the remaining part of the word can be formed starting from the current cell.

---

## ⭐ What I Learned

- Learned how to apply **DFS with Backtracking on a 2D grid**.
- Understood why **visited marking and restoration** are essential.
- Learned to **prune early** when the current character doesn't match.
- Understood that this is a **grid-based backtracking pattern**, where each recursive call chooses one of the four neighbouring cells.