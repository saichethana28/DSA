# Balanced Binary Tree

## Problem Statement
Given the root of a binary tree, determine whether it is height-balanced.

A binary tree is height-balanced if, for every node, the difference between the heights of its left and right subtrees is at most `1`.

### Examples

**Example 1:**
```text
Input: root = [3,9,20,null,null,15,7]
Output: true
```

**Example 2:**
```text
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

## Observations
- For every node, `abs(left height - right height) <= 1` must hold.
- An empty tree is balanced.
- If any subtree is unbalanced, the entire tree is unbalanced.
- We can solve this using brute force or an optimized bottom-up approach.
- Return `-1` from the helper function to indicate an unbalanced subtree.

## Brute Force

- Calculate the height of the left and right subtrees at every node.
- If their height difference exceeds `1`, return `false`.
- Recursively check whether the left and right subtrees are balanced.
- This approach repeatedly calculates subtree heights, making it less efficient.

```cpp
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(height(root->left),
                       height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int l = height(root->left);
        int r = height(root->right);

        if (abs(l - r) > 1) {
            return false;
        }

        return isBalanced(root->left) &&
               isBalanced(root->right);
    }
};
```

### Complexity
- **Time:** O(N²) in the worst case, because heights are recalculated at multiple nodes.
- **Space:** O(H) for the recursion stack, where H is the tree height.

## Optimal Approach: Bottom-Up DFS

- Calculate the heights of the left and right subtrees recursively.
- If either subtree returns `-1`, propagate `-1` immediately.
- If the height difference exceeds `1`, return `-1`.
- Otherwise, return `1 + max(left height, right height)`.
- In `isBalanced()`, return `false` if the helper returns `-1`; otherwise, return `true`.

```cpp
class Solution {
public:
    int check(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = check(root->left);
        int r = check(root->right);

        if (l == -1 || r == -1) {
            return -1;
        }

        if (abs(l - r) > 1) {
            return -1;
        }

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        int h = check(root);

        if (h == -1) {
            return false;
        }

        return true;
    }
};
```

### Complexity
- **Time:** O(N), because each node is visited only once.
- **Space:** O(H) for the recursion stack; O(N) in the worst case.

## Key Takeaways
- **Balanced condition:** `abs(left height - right height) <= 1`.
- **Brute force:** Calculate heights repeatedly, resulting in O(N²) worst-case time.
- **Optimal:** Calculate heights and check balance simultaneously in one traversal.
- Return `-1` to indicate an unbalanced subtree and propagate it upwards.
- **Interview pattern:** Use bottom-up DFS when a tree problem requires subtree information, such as height and balance.