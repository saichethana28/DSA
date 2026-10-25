# 222. Count Complete Tree Nodes

## Problem Statement
Given the root of a complete binary tree, return the total number of nodes in the tree.

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.

## Examples

### Example 1
Input: `root = [1,2,3,4,5,6]`

Output: `6`

### Example 2
Input: `root = []`

Output: `0`

## Observations
- If the root is `NULL`, the number of nodes is `0`.
- Calculate the leftmost height and rightmost height of the tree.
- If both heights are equal, the tree is perfect, meaning all levels are completely filled.
- A perfect binary tree of height `h` contains `2^h - 1` nodes.
- If the heights differ, recursively count the nodes in the left and right subtrees.

## Approach

- Find the leftmost height by repeatedly moving to the left child.
- Find the rightmost height by repeatedly moving to the right child.
- If both heights are equal, return `(1 << h) - 1`.
- Otherwise, count the root and recursively count both subtrees.
- This avoids visiting every node when a subtree is perfect.

```cpp
class Solution {
public:
    int findleftheight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int h = 0;
        while (root != NULL) {
            h++;
            root = root->left;
        }

        return h;
    }

    int findrightheight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int h = 0;
        while (root != NULL) {
            h++;
            root = root->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = findleftheight(root);
        int r = findrightheight(root);

        if (l == r) {
            return (1 << l) - 1;
        }

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
```

### Complexity
Let `N` be the number of nodes and `H` be the height of the tree.

- **Time:** `O(log² N)` — calculating the heights takes `O(log N)` per recursive call, and the recursion has `O(log N)` levels for a complete binary tree.
- **Space:** `O(log N)` — recursive call stack.

## Key Takeaways
- A complete binary tree allows optimisations that are not possible for an arbitrary binary tree.
- Equal leftmost and rightmost heights indicate a perfect binary tree.
- A perfect binary tree with height `h` has `(2^h) - 1` nodes.
- Use recursive counting only when the subtree is not perfect.
- The optimised approach runs in `O(log² N)` instead of `O(N)`.