# Binary Tree Level Order Traversal

## Problem Statement
Given the root of a binary tree, return the level order traversal of its nodes' values, from left to right, level by level.

### Examples

**Example 1:**
```text
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**
```text
Input: root = [1]
Output: [[1]]
```

## Observations
- Level order traversal visits nodes level by level.
- Use a **queue (FIFO)** to process nodes in order.
- Store the current queue size in `n` to process only the current level.
- Add the left child first, followed by the right child.
- If the root is `NULL`, return an empty vector.

## Approach: BFS Using Queue

- Initialize a queue and push the root node.
- While the queue is not empty, create a vector for the current level.
- Store `q.size()` in `n` to know how many nodes belong to this level.
- Process exactly `n` nodes, adding their values to the level vector and pushing their children into the queue.
- Add the completed level to the answer.

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }

                level.push_back(node->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
```

### Complexity
- **Time:** O(N), because every node is processed once.
- **Space:** O(N) for the queue and result in the worst case.

## Key Takeaways
- **Level order traversal = BFS (Breadth-First Search).**
- Use a queue because it follows FIFO: First In, First Out.
- `int n = q.size()` is the key to separating levels.
- Process exactly `n` nodes before moving to the next level.
- Push the left child before the right child to maintain left-to-right order.