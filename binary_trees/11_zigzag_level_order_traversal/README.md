# Binary Tree Zigzag Level Order Traversal

## Problem Statement
Given the root of a binary tree, return its zigzag level order traversal.

The first level is traversed from left to right, the second from right to left, the third from left to right, and so on.

### Examples

**Example 1:**
```text
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```

**Example 2:**
```text
Input: root = [1]
Output: [[1]]
```

## Observations
- Use BFS with a queue to process nodes level by level.
- Store the current level's node count using `q.size()`.
- Initially, traverse from left to right.
- Reverse every alternate level to achieve zigzag order.
- Toggle the direction after processing each level.

## Approach: BFS Using Queue

- Push the root into the queue.
- Process all nodes belonging to the current level.
- Push each node's left and right children into the queue.
- Store the current level's values in a vector.
- If the direction is right to left, reverse the level before adding it to the answer.

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool ltor = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

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

            if (!ltor) {
                reverse(level.begin(), level.end());
            }

            ltor = !ltor;
            ans.push_back(level);
        }

        return ans;
    }
};
```

### Complexity
- **Time:** O(N + Σ Lᵢ log Lᵢ) with the per-level reversal; more simply, O(N + total reversal cost), where N is the number of nodes and Lᵢ is the size of level i. The worst-case time complexity is O(N log N).
- **Space:** O(N) for the queue and result in the worst case.

## Key Takeaways
- **Zigzag traversal = Level order traversal + alternate direction.**
- Use BFS with a queue to process nodes level by level.
- `q.size()` determines how many nodes belong to the current level.
- Use a boolean variable to track the traversal direction.
- Reverse the level when traversing right to left.
- Toggle the direction after each level.