# Binary Tree Maximum Path Sum

## Problem Statement
Given the root of a binary tree, return the maximum path sum of any non-empty path.

A path is a sequence of nodes connected by edges. Each node can appear at most once in the path, and the path does not need to pass through the root.

### Examples

**Example 1:**
```text
Input: root = [1,2,3]
Output: 6
Explanation: The maximum path is 2 → 1 → 3.
```

**Example 2:**
```text
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The maximum path is 15 → 20 → 7.
```

## Observations
- A maximum path can pass through any node, not necessarily the root.
- At each node, calculate the maximum contribution from its left and right subtrees.
- Ignore negative subtree sums using `max(0, sum)`.
- Update the global maximum using `root->val + left + right`.
- Return only one branch's contribution because a parent cannot use both branches simultaneously.
- Initialize `maxi` to `INT_MIN` to handle trees containing only negative values.

## Approach 1: Brute Force

- Consider every node as a possible highest point of a path.
- Calculate the maximum downward path sum from its left and right subtrees.
- Combine the node's value with both contributions.
- Update the global maximum.
- Recalculating subtree path sums makes this approach inefficient.

```cpp
class Solution {
public:
    int maxGain(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = max(0, maxGain(root->left));
        int r = max(0, maxGain(root->right));

        return root->val + max(l, r);
    }

    void findMax(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return;
        }

        int l = max(0, maxGain(root->left));
        int r = max(0, maxGain(root->right));

        maxi = max(maxi, root->val + l + r);

        findMax(root->left, maxi);
        findMax(root->right, maxi);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMax(root, maxi);
        return maxi;
    }
};
```

### Complexity
- **Time:** O(N²) in the worst case, because subtree gains may be recalculated for multiple nodes.
- **Space:** O(H) for the recursion stack, where H is the tree height.

## Approach 2: Optimal Approach (Postorder DFS)

- Recursively calculate the maximum downward path sum for the left and right subtrees.
- Use `max(0, subtree sum)` to ignore negative contributions.
- Update `maxi` with `root->val + l + r`, allowing a path through both children.
- Return `root->val + max(l, r)` so the parent can extend the path through only one child.
- Initialize `maxi` to `INT_MIN` so an all-negative tree returns its largest node value.

```cpp
class Solution {
public:
    int sum(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }

        int l = max(0, sum(root->left, maxi));
        int r = max(0, sum(root->right, maxi));

        maxi = max(maxi, root->val + l + r);

        return root->val + max({l, r, 0});
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        sum(root, maxi);
        return maxi;
    }
};
```

### Complexity
- **Time:** O(N), because each node is visited exactly once.
- **Space:** O(H) for the recursion stack; O(N) in the worst case.

## Key Takeaways
- **Maximum path through a node:** `root->val + left + right`.
- **Contribution returned to the parent:** `root->val + max(left, right)`.
- Use `max(0, subtree sum)` to discard negative contributions.
- Initialize the global maximum to `INT_MIN` to handle all-negative trees.
- **Brute force:** Recalculates subtree gains, giving O(N²) worst-case time.
- **Optimal:** Calculates contributions and updates the answer in one traversal, giving O(N) time.
- **Interview pattern:** Use postorder DFS when a tree problem requires information from both subtrees.