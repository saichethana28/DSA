# Diameter of Binary Tree

## Problem Statement
Given the root of a binary tree, return its diameter.

The diameter is the **length of the longest path between any two nodes** in the tree. The path may or may not pass through the root.

**Note:** The diameter is measured in the number of edges, not nodes.

### Examples

**Example 1:**
```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: The longest path is [4,2,1,3] or [5,2,1,3], with 3 edges.
```

**Example 2:**
```text
Input: root = [1,2]
Output: 1
```

## Observations
- The diameter passing through a node is `left height + right height`.
- Calculate the heights of the left and right subtrees.
- The longest path might pass through any node, not necessarily the root.
- Update the maximum diameter at every node.
- Height is measured in nodes, but the diameter is measured in edges.

## Approach 1: Brute Force

- Calculate the left and right subtree heights at each node.
- Calculate the diameter passing through the current node using `left height + right height`.
- Update the maximum diameter.
- Recursively calculate the diameter of the left and right subtrees.
- Repeated height calculations make this approach less efficient.

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

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);

        int current = l + r;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(current, max(leftDiameter, rightDiameter));
    }
};
```

### Complexity
- **Time:** O(N²) in the worst case because subtree heights are repeatedly calculated.
- **Space:** O(H) for the recursion stack, where H is the tree height.

## Approach 2: Optimal Approach (Height + Diameter Together)

- Use a helper function to calculate the height of each node.
- Recursively calculate the left and right subtree heights.
- Update the maximum diameter using `left height + right height`.
- Return `1 + max(left height, right height)` to calculate the current node's height.
- Maintain the diameter in a reference variable so every node can update it.

```cpp
class Solution {
public:
    int height(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0;
        }

        int l = height(root->left, maxi);
        int r = height(root->right, maxi);

        maxi = max(maxi, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }
};
```

### Complexity
- **Time:** O(N), because every node is visited exactly once.
- **Space:** O(H) for the recursion stack; O(N) in the worst case.

## Key Takeaways
- **Diameter through a node = left height + right height.**
- The diameter is measured in edges, so we use `l + r`.
- The maximum diameter may occur at any node.
- **Brute force:** Recalculates heights repeatedly, giving O(N²) worst-case time.
- **Optimal:** Calculates height and updates diameter in one traversal, giving O(N) time.
- **Interview pattern:** When multiple tree properties depend on subtree heights, calculate them together using bottom-up DFS.