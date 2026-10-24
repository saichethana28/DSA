# Boundary Traversal of Binary Tree

## Problem Statement
Given the root of a binary tree, return its boundary traversal in **anti-clockwise order**, starting from the root.

The boundary consists of:
1. Root node.
2. Left boundary (excluding leaf nodes).
3. All leaf nodes from left to right.
4. Right boundary in bottom-up order (excluding leaf nodes).

### Examples

**Example 1:**
```text
Input: root = [1,2,3,4,5,6,7]
Output: [1,2,4,5,6,7,3]
```

**Example 2:**
```text
Input: root = [1,2,3,null,4]
Output: [1,2,4,3]
```

## Observations
- Traverse the boundary in anti-clockwise order.
- Add the root first, but avoid adding it twice if it is a leaf.
- Left boundary: prefer the left child; otherwise, move to the right child.
- Leaves: traverse from left to right and include only leaf nodes.
- Right boundary: prefer the right child; otherwise, move to the left child, then reverse the collected nodes.

## Approach: Boundary Traversal

- **`isleaf()`** checks whether a node has no children.
- **`addleft()`** collects non-leaf nodes along the left boundary from top to bottom.
- **`addleaves()`** recursively collects all leaf nodes from left to right.
- **`addright()`** collects non-leaf nodes along the right boundary and adds them in reverse order.
- Combine the four parts in the required order.

```cpp
class Solution {
public:
    bool isleaf(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }

    void addleft(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;

        while (curr) {
            if (!isleaf(curr)) {
                res.push_back(curr->data);
            }

            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void addright(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isleaf(curr)) {
                temp.push_back(curr->data);
            }

            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    void addleaves(TreeNode* root, vector<int>& res) {
        if (isleaf(root)) {
            res.push_back(root->data);
            return;
        }

        if (root->left) {
            addleaves(root->left, res);
        }

        if (root->right) {
            addleaves(root->right, res);
        }
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> res;

        if (root == NULL) {
            return res;
        }

        if (!isleaf(root)) {
            res.push_back(root->data);
        }

        addleft(root, res);
        addleaves(root, res);
        addright(root, res);

        return res;
    }
};
```

### Complexity
- **Time:** O(N), because every node is visited at most a constant number of times.
- **Space:** O(H) auxiliary space for recursion and the temporary right-boundary vector, where H is the tree height. The result vector requires O(N) space.

## Key Takeaways
- **Boundary traversal = Root + Left boundary + Leaves + Reversed right boundary.**
- Exclude leaf nodes from both boundaries to avoid duplicates.
- Left boundary prefers the left child; otherwise, move right.
- Right boundary prefers the right child; otherwise, move left.
- Reverse the right boundary before appending it.
- Handle a single-node tree separately by avoiding duplicate insertion of the root.