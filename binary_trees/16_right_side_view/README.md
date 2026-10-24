# Binary Tree Right Side View

## Problem Statement
Given the root of a binary tree, return the values of the nodes visible when the tree is viewed from the right side, ordered from top to bottom.

## Examples

### Example 1
**Input:** `root = [1,2,3,null,5,null,4]`

**Output:** `[1,3,4]`

### Example 2
**Input:** `root = [1,2,3,4,null,null,null,5]`

**Output:** `[1,3,4,5]`

## Observations
- The rightmost node at each level is visible from the right side.
- BFS processes nodes level by level using a queue.
- DFS can solve the problem by visiting the right child before the left child.
- If the tree is empty, return an empty vector.

## Brute Force — Recursive DFS

- Use recursion to traverse the tree.
- Visit the right child before the left child.
- The first node visited at each depth is the rightmost node for that level.
- If `depth == ans.size()`, this is the first node encountered at that depth, so add its value.

### Code
```cpp
class Solution {
public:
    void solve(TreeNode* root, int depth, vector<int>& ans) {
        if(root == NULL) return;

        if(depth == ans.size()) {
            ans.push_back(root->val);
        }

        solve(root->right, depth + 1, ans);
        solve(root->left, depth + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};
```

### Complexity
- **Time:** `O(N)` — every node is visited once.
- **Space:** `O(H)` auxiliary recursion stack, where `H` is the tree height; the answer requires `O(H)` space.

## Optimal Approach — Iterative BFS

- Use a queue to perform level-order traversal.
- For each level, store the number of nodes currently in the queue.
- Process exactly that many nodes.
- Update `value` with every node's value, so it holds the last node's value at that level.
- Add `value` to the answer after processing the entire level.

### Code
```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            int value = -1;

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                value = node->val;
            }

            ans.push_back(value);
        }

        return ans;
    }
};
```

### Complexity
- **Time:** `O(N)` — every node is visited once.
- **Space:** `O(N)` — the queue can store up to `O(N)` nodes.

## Key Takeaways
- **Recursive DFS:** Visit right before left; the first node at each depth is visible.
- **Iterative BFS:** The last node processed at each level is visible.
- `depth == ans.size()` identifies the first node reached at a new depth in DFS.
- Both approaches take `O(N)` time.
- Use DFS when you want a concise recursive solution; use BFS when you prefer level-by-level processing.