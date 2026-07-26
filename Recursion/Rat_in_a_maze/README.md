# Rat in a Maze

## Problem

Given an `n × n` binary matrix where:
- `1` represents an open cell.
- `0` represents a blocked cell.

Find all possible paths from the top-left cell `(0,0)` to the bottom-right cell `(n-1,n-1)`. The rat can move in four directions:
- Down (D)
- Left (L)
- Right (R)
- Up (U)

A cell cannot be visited more than once in the same path. Return all valid paths in lexicographical order.

**Example**

```text
Input:
maze =
[
 [1,0,0,0],
 [1,1,0,1],
 [1,1,0,0],
 [0,1,1,1]
]

Output:
["DDRDRR","DRDDRR"]
```

---

# Optimal Approach

## Key Observations

- From every cell, the rat has four possible moves: **Down, Left, Right, and Up**.
- Revisiting the same cell creates cycles, so each visited cell must be temporarily marked.
- After exploring all paths from a cell, restore it so it can be used in other paths (Backtracking).
- Exploring directions in the order **D → L → R → U** generates paths in lexicographical order.

## Approach

- Start DFS from `(0,0)`.
- If the current cell is outside the grid, blocked, or already visited, return.
- If the destination `(n-1,n-1)` is reached, store the current path.
- Mark the current cell as visited.
- Explore all four directions recursively while appending the corresponding direction to the current path.
- After every recursive call, remove the last direction from the path.
- Restore the current cell before returning to enable other possible paths.

## Code

```cpp
class Solution {
public:
    void solve(vector<vector<int>>& maze, vector<string>& ans, string& curr, int r, int c) {
        if (r < 0 || c < 0 || r >= maze.size() || c >= maze[0].size() ||
            maze[r][c] == -1 || maze[r][c] == 0) {
            return;
        }

        if (r == maze.size() - 1 && c == maze[0].size() - 1) {
            ans.push_back(curr);
            return;
        }

        maze[r][c] = -1;

        curr.push_back('D');
        solve(maze, ans, curr, r + 1, c);
        curr.pop_back();

        curr.push_back('L');
        solve(maze, ans, curr, r, c - 1);
        curr.pop_back();

        curr.push_back('R');
        solve(maze, ans, curr, r, c + 1);
        curr.pop_back();

        curr.push_back('U');
        solve(maze, ans, curr, r - 1, c);
        curr.pop_back();

        maze[r][c] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string curr = "";
        solve(maze, ans, curr, 0, 0);
        return ans;
    }
};
```

### Complexity Analysis

**Time Complexity:** **O(4^(N²))**

**Reasoning:**
- Each cell can recursively explore up to four directions.
- Backtracking explores all possible valid paths from the source to the destination.
- Hence, the worst-case complexity is exponential.

**Space Complexity:** **O(N²)**

**Reasoning:**
- The recursion stack can grow up to `O(N²)` in the worst case.
- No extra visited matrix is used since the maze itself is modified during recursion.

---

# Interview Notes

- This is a classic **DFS + Backtracking** problem.
- The recursion state is: **"Find all paths starting from the current cell."**
- Mark the current cell as visited before exploring neighbors and restore it while backtracking.
- Always perform boundary and validity checks before accessing a cell.
- Exploring directions in **D → L → R → U** ensures lexicographical ordering of the generated paths.

---

# What I Learned ⭐

- How to apply DFS with backtracking on a 2D grid.
- How to avoid cycles by temporarily marking visited cells.
- How to build path strings during recursion using push and pop operations.
- How backtracking restores both the path and the grid state, allowing exploration of all possible solutions.