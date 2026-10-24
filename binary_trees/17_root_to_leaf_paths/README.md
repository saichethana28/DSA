# Root-to-Leaf Paths in Binary Tree

## Problem Statement
Given the root of a binary tree, return all root-to-leaf paths.

A leaf node is a node with no left or right child.

## Examples

### Example 1
**Input:**
```text
        1
       / \
      2   3
     / \
    4   5
```

**Output:** `[[1,2,4],[1,2,5],[1,3]]`

### Example 2
**Input:** `root = [1,2,3]`

**Output:** `[[1,2],[1,3]]`

## Observations
- Every path starts at the root and ends at a leaf.
- DFS explores all possible root-to-leaf paths.
- Maintain the current path using a vector.
- Save the path whenever a leaf is reached.
- Use backtracking to remove nodes when returning from recursion.

## Approach — DFS + Backtracking

- If the current node is `NULL`, return.
- Add the current node's value to the current path.
- If the node is a leaf, save the current path.
- Otherwise, recursively explore the left and right subtrees.
- Remove the current node from the path to backtrack.

### Code
```cpp
class Solution {
public:
    void solve(Node* root, vector<int>& curr, vector<vector<int>>& ans) {
        if (root == NULL) return;

        curr.push_back(root->data);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(curr);
        } else {
            solve(root->left, curr, ans);
            solve(root->right, curr, ans);
        }

        curr.pop_back();
    }

    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(root, curr, ans);
        return ans;
    }
};
```

### Complexity
- **Time:** `O(N + P)`, where `N` is the number of nodes and `P` is the total number of elements across all returned paths.
- **Auxiliary Space:** `O(H)`, where `H` is the tree height, for the recursion stack and current path, excluding the output.

## Key Takeaways
- **DFS** explores every root-to-leaf path.
- **Leaf condition:** `root->left == NULL && root->right == NULL`.
- **Backtracking:** Add the node before exploring and remove it when returning.
- Save the path only when a leaf is reached.
- Remember the pattern: **Add → Explore → Save → Backtrack**.