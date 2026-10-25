# Unique Binary Tree — GFG

## Problem Statement
Given two binary tree traversals represented by integers, determine whether a unique binary tree can be constructed.

- `1` → Preorder
- `2` → Inorder
- `3` → Postorder

Return `true` if a unique binary tree can be constructed; otherwise, return `false`.

## Examples

### Example 1
Input: `a = 1, b = 2`

Output: `true`

Explanation: Preorder and Inorder traversals uniquely determine a binary tree.

### Example 2
Input: `a = 2, b = 2`

Output: `false`

Explanation: Two Inorder traversals are insufficient to uniquely determine a binary tree.

## Observations
- Inorder + Preorder uniquely determines a binary tree.
- Inorder + Postorder uniquely determines a binary tree.
- Preorder + Postorder cannot uniquely determine a general binary tree.
- Two identical traversal types are insufficient to guarantee a unique tree.

## Approach

- Check whether `a` is Inorder (`2`) and `b` is either Preorder (`1`) or Postorder (`3`).
- Otherwise, check whether `b` is Inorder (`2`) and `a` is either Preorder (`1`) or Postorder (`3`).
- If either condition holds, return `true`.
- Otherwise, return `false`.

```cpp
class Solution {
public:
    bool uniqueBinaryTree(int a, int b) {
        if (a == 2 && (b == 1 || b == 3)) {
            return true;
        }
        else if (b == 2 && (a == 1 || a == 3)) {
            return true;
        }
        else {
            return false;
        }
    }
};
```

### Complexity
- **Time:** `O(1)` — only a constant number of conditions are checked.
- **Space:** `O(1)` — no additional data structures are used.

## Key Takeaways
- Inorder + Preorder uniquely determines a binary tree.
- Inorder + Postorder uniquely determines a binary tree.
- Preorder + Postorder does not uniquely determine a general binary tree.
- Check whether one traversal is Inorder to solve the problem in constant time.