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
- Use level-order traversal (BFS).
- Process each level separately.
- The last node processed at each level is visible from the right side.
- Store the last node's value in the answer.
- If the tree is empty, return an empty vector.

## Approach

- Use a queue to perform BFS.
- For each level, store the number of nodes currently in the queue.
- Process exactly that many nodes.
- Update `value` with each node's value, so it holds the last node's value at that level.
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
        q.push({root});

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
- **Space:** `O(N)` — the queue can store up to `N` nodes.

## Key Takeaways
- **BFS** processes nodes level by level.
- `n = q.size()` captures the number of nodes at the current level.
- Updating `value` for every node ensures it holds the last node's value.
- The last node processed at each level forms the right-side view.
- The same approach can find the left-side view by recording the first node at each level.