# Maximum Depth of Binary Tree

## Problem Statement
Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node to a leaf node.

### Examples

**Example 1:**
```text
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

**Example 2:**
```text
Input: root = [1,null,2]
Output: 2
```

## Observations
- An empty tree has a depth of `0`.
- The depth of a node is `1 + max(left subtree depth, right subtree depth)`.
- Recursively calculate the depth of both subtrees.
- Return the maximum of the two depths plus `1` for the current node.

## Approach: Recursion (DFS)

- If the root is `NULL`, return `0`.
- Recursively calculate the left subtree's maximum depth.
- Recursively calculate the right subtree's maximum depth.
- Return `1 + max(left, right)`.

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l, r);
    }
};
```

### Complexity
- **Time:** O(N), where N is the number of nodes, because every node is visited once.
- **Space:** O(H) for the recursion stack, where H is the height of the tree; O(N) in the worst case.

## Key Takeaways
- **Maximum depth = 1 + max(left depth, right depth).**
- The base case for a `NULL` node is `0`.
- Use DFS recursion to explore both subtrees.
- `max(l, r)` selects the deeper subtree.
- This recursive pattern is useful for many binary tree problems involving height or depth.