# Same Tree

## Problem Statement
Given the roots of two binary trees `p` and `q`, determine whether they are identical.

Two binary trees are identical if they have the same structure and the same node values.

### Examples

**Example 1:**
```text
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

**Example 2:**
```text
Input: p = [1,2], q = [1,null,2]
Output: false
```

## Observations
- Both trees must have the same structure and node values.
- If both nodes are `NULL`, their subtrees are identical.
- If exactly one node is `NULL`, the structures differ.
- If node values differ, the trees are not identical.
- Otherwise, recursively compare the left and right subtrees.

## Approach: Recursion (DFS)

- If both nodes are `NULL`, return `true`.
- If exactly one node is `NULL`, return `false`.
- If their values differ, return `false`.
- Recursively compare their left and right subtrees.
- Return `true` only if both subtree comparisons are `true`.

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
```

### Complexity
- **Time:** O(N), where N is the number of nodes, because each corresponding node is compared at most once.
- **Space:** O(H), where H is the maximum tree height, due to the recursion stack; O(N) in the worst case.

## Key Takeaways
- **Both `NULL` → `true`.**
- **Exactly one `NULL` → `false`.**
- **Different node values → `false`.**
- Both left and right subtree comparisons must return `true`.
- Follow the pattern: **NULL checks → value check → recursive comparison.**