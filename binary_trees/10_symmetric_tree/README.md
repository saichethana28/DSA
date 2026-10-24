# Symmetric Tree

## Problem Statement
Given the root of a binary tree, determine whether it is symmetric around its centre.

A binary tree is symmetric if its left and right subtrees are mirror images of each other.

### Examples

**Example 1:**
```text
Input: root = [1,2,2,3,4,4,3]
Output: true
```

**Example 2:**
```text
Input: root = [1,2,2,null,3,null,3]
Output: false
```

## Observations
- A tree is symmetric if its left and right subtrees are mirror images.
- Both nodes being `NULL` means they are symmetric.
- If only one node is `NULL`, the trees are not symmetric.
- The values of corresponding mirror nodes must be equal.
- Compare the left child of one subtree with the right child of the other, and vice versa.

## Approach 1: Recursive DFS

- Compare the left and right subtrees using a helper function.
- If both nodes are `NULL`, return `true`.
- If only one node is `NULL`, return `false`.
- If their values differ, return `false`.
- Recursively compare `n1->left` with `n2->right` and `n1->right` with `n2->left`.

```cpp
class Solution {
public:
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (n1 == NULL && n2 == NULL) {
            return true;
        }

        if (n1 == NULL || n2 == NULL) {
            return false;
        }

        if (n1->val != n2->val) {
            return false;
        }

        return isMirror(n1->left, n2->right) &&
               isMirror(n1->right, n2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return isMirror(root->left, root->right);
    }
};
```

### Complexity
- **Time:** O(N), because each node is visited at most once.
- **Space:** O(H) for the recursion stack, where H is the tree height; O(N) in the worst case.

## Approach 2: Iterative BFS Using a Queue

- Use a queue to store pairs of nodes that must be mirror images.
- Initially, insert the root's left and right children as a pair.
- If both nodes are `NULL`, continue.
- If only one is `NULL` or their values differ, return `false`.
- Add the outer pair and inner pair of children to the queue.

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});

        while (!q.empty()) {
            auto [n1, n2] = q.front();
            q.pop();

            if (n1 == NULL && n2 == NULL) {
                continue;
            }

            if (n1 == NULL || n2 == NULL) {
                return false;
            }

            if (n1->val != n2->val) {
                return false;
            }

            q.push({n1->left, n2->right});
            q.push({n1->right, n2->left});
        }

        return true;
    }
};
```

### Complexity
- **Time:** O(N), because each node is processed at most once.
- **Space:** O(N) in the worst case for the queue.

## Key Takeaways
- **Symmetric tree = left and right subtrees are mirror images.**
- Compare the outer children (`left-left` with `right-right`) and inner children (`left-right` with `right-left`) through paired mirror checks.
- **Recursive approach:** Use DFS to compare mirror nodes.
- **Iterative approach:** Use a queue to process pairs of mirror nodes.
- Remember the base cases: both `NULL` → `true`; exactly one `NULL` → `false`.