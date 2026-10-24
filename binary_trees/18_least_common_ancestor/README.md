# Lowest Common Ancestor of a Binary Tree

## Problem Statement
Given the root of a binary tree and two nodes `p` and `q`, find their Lowest Common Ancestor (LCA).

The LCA is the lowest node in the tree that has both `p` and `q` as descendants. A node can be a descendant of itself.

## Examples

### Example 1
**Input:** `root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1`

**Output:** `3`

**Explanation:** Node `3` is the lowest node having both `5` and `1` as descendants.

### Example 2
**Input:** `root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4`

**Output:** `5`

**Explanation:** Node `5` is the LCA because a node can be an ancestor of itself.

## Observations
- If the current node is `NULL`, return `NULL`.
- If the current node is `p` or `q`, return that node.
- Recursively search the left and right subtrees.
- If both subtrees return non-`NULL` nodes, the current node is the LCA.
- If only one subtree returns a non-`NULL` node, propagate that result upward.

## Approach — Recursive DFS

- Check the base cases: `root == NULL`, `root == p`, or `root == q`.
- Recursively find `p` or `q` in the left subtree.
- Recursively find `p` or `q` in the right subtree.
- If the left result is `NULL`, return the right result.
- If the right result is `NULL`, return the left result.
- If both results are non-`NULL`, return the current root.

### Code
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l == NULL) {
            return r;
        }
        else if(r == NULL) {
            return l;
        }
        else {
            return root;
        }
    }
};
```

### Complexity
- **Time:** `O(N)` — each node is visited at most once.
- **Auxiliary Space:** `O(H)` — recursion stack, where `H` is the height of the tree. Worst case: `O(N)` for a skewed tree.

## Key Takeaways
- **Base case:** Return the current node if it is `NULL`, `p`, or `q`.
- **Both sides non-NULL:** The current node is the LCA.
- **One side non-NULL:** Propagate that result upward.
- **Both sides NULL:** Neither target was found in that subtree.
- Remember the pattern: **Search Left → Search Right → Combine Results**.