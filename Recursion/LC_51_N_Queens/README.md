# N-Queens

## Problem

Given an integer `n`, place `n` queens on an `n × n` chessboard such that no two queens attack each other. Return all distinct valid board configurations.

**Example:**

```text
Input:  n = 4

Output:
[
 [".Q..","...Q","Q...","..Q."],
 ["..Q.","Q...","...Q",".Q.."]
]
```

---

# Brute Force Approach

## Approach

- Place one queen in each row using backtracking and try every column for the current row.
- Before placing a queen, scan the upper column, upper-left diagonal, and upper-right diagonal to check if the position is safe.
- If the position is safe, place the queen and recursively solve for the next row.
- If no valid placement is possible, backtrack by removing the previously placed queen and try the next column.
- Store the current board configuration once queens are successfully placed in all rows.

## Code

```cpp
class Solution {
public:
    bool right(vector<string>&curr, int r, int col){
        for(int i=r-1,j=col+1;i>=0 && j<curr[0].size();i--,j++){
            if(curr[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    bool up(vector<string>&curr, int r, int col){
        for(int i=0;i<r;i++){
            if(curr[i][col]=='Q'){
                return false;
            }
        }
        return true;
    }
    bool left(vector<string>&curr, int r, int col){
        for(int i=r-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(curr[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    bool safe(vector<string>&curr, int r, int col){
        return up(curr,r,col) && left(curr,r,col) && right(curr,r,col);
    }
    void solve(vector<vector<string>> &ans , vector<string>&curr, int n, int r){
        if(r==n){
            ans.push_back(curr);
            return;
        }
        for(int col=0;col<n;col++){
            if(safe(curr,r,col)){
                curr[r][col]='Q';
                solve(ans,curr,n,r+1);
                curr[r][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>curr;
        string row(n,'.');
        for(int i=0;i<n;i++){
            curr.push_back(row);
        }
        solve(ans,curr,n,0);
        return ans;
    }
};
```

### Complexity Analysis

**Time Complexity:** **O(N! × N)**

- `N!` possible queen placements are explored in the recursion tree.
- Each placement requires an **O(N)** safety check by scanning the column and both diagonals.

**Space Complexity:** **O(N² + N)**

- `O(N²)` for storing the current chessboard.
- `O(N)` recursion stack depth.

---

# Optimal Approach

## Key Observations

- Scanning the board repeatedly to check whether a position is safe is expensive.
- A queen always occupies exactly one column, one `row - col` diagonal, and one `row + col` diagonal.
- Using three boolean arrays allows checking whether these lines are already occupied in **O(1)** time.

## Approach

- Initialize three boolean arrays to track occupied columns, left diagonals (`row - col + (n - 1)`), and right diagonals (`row + col`).
- Place one queen in each row and iterate through every column to find a valid position.
- Before placing a queen, check whether the corresponding column and diagonals are unoccupied using the boolean arrays.
- If the position is safe, place the queen, mark the corresponding column and diagonals as occupied, and recursively solve for the next row.
- After returning from recursion, remove the queen and unmark the column and diagonals to explore other possible configurations.
- Store the board when all `n` queens have been successfully placed.

## Code

```cpp
class Solution {
public:
    void solve(vector<vector<string>> &ans , vector<string>&curr, int n, int r,vector<bool>&col,vector<bool>&left,vector<bool>&right){
        if(r==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(!col[i] && !left[r-i+(n-1)] && !right[r+i]){
                curr[r][i]='Q';
                col[i]=true;
                left[r-i+(n-1)]=true;
                right[r+i]=true;
                solve(ans,curr,n,r+1,col,left,right);
                col[i]=false;
                left[r-i+(n-1)]=false;
                right[r+i]=false;
                curr[r][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>curr;
        vector<bool>col(n,false);
        vector<bool>left(2*n-1,false);
        vector<bool>right(2*n-1,false);
        string row(n,'.');
        for(int i=0;i<n;i++){
            curr.push_back(row);
        }
        solve(ans,curr,n,0,col,left,right);
        return ans;
    }
};
```

### Complexity Analysis

**Time Complexity:** **O(N!)**

- The recursion explores all valid queen placements.
- Each safety check takes **O(1)** using the three boolean arrays.

**Space Complexity:** **O(N² + N)**

- `O(N²)` for storing the current chessboard.
- `O(N)` for the three boolean arrays and recursion stack.

---

# Interview Notes

- The recursion state is **"Place a queen in the current row."**
- Since queens are placed row by row, only the **column**, **upper-left diagonal**, and **upper-right diagonal** need to be checked.
- The optimization is not changing the recursion—it only replaces the `safe()` function from **O(N)** scanning to **O(1)** lookups.
- The left diagonal is uniquely identified by `row - col + (n - 1)` and the right diagonal by `row + col`.

---

# What I Learned ⭐

- Optimizing a backtracking solution often comes from optimizing the validity check rather than changing the recursion.
- Diagonals can be uniquely identified using simple mathematical formulas instead of scanning the board.
- Boolean arrays can act as hash tables to perform constant-time safety checks.
- Proper backtracking requires restoring both the board and all auxiliary data structures after each recursive call.