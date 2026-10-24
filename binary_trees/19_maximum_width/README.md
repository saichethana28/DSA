# 662. Maximum Width of Binary Tree

## Problem Statement
Given the root of a binary tree, return the maximum width among all levels.

The width of a level is the length between the leftmost and rightmost non-null nodes, including the null nodes between them.

## Examples

### Example 1
Input: `root = [1,3,2,5,3,null,9]`

Output: `4`

Explanation: The third level has nodes at positions 5, 3, and 9, with a width of 4.

### Example 2
Input: `root = [1,3,2,5,null,null,9,6,null,7]`

Output: `7`

## Observations
- Use level-order traversal (BFS) to process each level.
- Assign indices to nodes as if the tree were a complete binary tree.
- For a node at index `i`, its left child has index `2*i + 1` and its right child has index `2*i + 2`.
- The width of a level is `last - first + 1`.
- Normalise indices at every level to prevent unnecessary index growth.

## Approach

- Use a queue to store each node and its index.
- Process all nodes at the current level.
- Store the minimum index of the level as `mini`.
- Calculate the normalised index using `curr = lvl - mini`.
- Assign indices to the children using the complete binary tree indexing rules.
- Update the maximum width after processing each level.

```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        long long maxi = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long long first = 0, last = 0;
            long long mini = q.front().second;

            for (int i = 0; i < n; i++) {
                auto [node, lvl] = q.front();
                q.pop();

                long long curr = lvl - mini;

                if (i == 0) first = curr;
                if (i == n - 1) last = curr;

                if (node->left) {
                    q.push({node->left, 2 * curr + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * curr + 2});
                }
            }

            maxi = max(maxi, last - first + 1);
        }

        return (int)maxi;
    }
};
```

### Complexity
- **Time:** `O(N)` — each node is processed once.
- **Space:** `O(N)` — the queue can store up to `O(N)` nodes.

## Key Takeaways
- Use BFS to process the tree level by level.
- Complete binary tree indexing helps account for gaps between nodes.
- Width is `last - first + 1`, not simply the number of nodes.
- Normalising indices reduces unnecessary index growth.
- Use `long long` for indices to reduce the risk of integer overflow.