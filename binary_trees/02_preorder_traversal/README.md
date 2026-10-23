# Binary Tree Preorder Traversal

## Problem Statement
Given the root of a binary tree, return its preorder traversal of node values.

Preorder traversal follows **Root → Left → Right**.

### Examples

**Example 1:**
```text
Input: root = [1,null,2,3]
Output: [1,2,3]
```

**Example 2:**
```text
Input: root = [1,2,3]
Output: [1,2,3]
```

## Observations
- Visit the **root node first**.
- Traverse the left subtree before the right subtree.
- Order: **Root → Left → Right**.
- A stack can simulate recursion for iterative traversal.
- Handle an empty tree by returning an empty vector.

## Brute Force

- Use recursion to traverse the tree.
- First, add the root's value to the result.
- Recursively traverse the left subtree.
- Recursively traverse the right subtree.

```cpp
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
```

### Complexity
- **Time:** O(N), where N is the number of nodes.
- **Space:** O(H) for the recursion stack, where H is the tree height; O(N) in the worst case.

## Optimal Approach

- Use a stack to perform iterative traversal.
- Push the root onto the stack.
- Pop a node, add its value to the result, and push its children.
- **Push the right child first, then the left child**, so the left child is processed first.

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if (node->right != NULL)
                st.push(node->right);

            if (node->left != NULL)
                st.push(node->left);
        }

        return ans;
    }
};
```

### Complexity
- **Time:** O(N), as every node is visited once.
- **Space:** O(N) in the worst case for the stack.

## Key Takeaways
- **Preorder = Root → Left → Right.**
- Add the current node before visiting its children.
- In iterative traversal, push **right before left**.
- Use recursion for a simple solution or a stack to avoid recursive calls.
- Remember the traversal patterns:
  - **Preorder:** Root → Left → Right
  - **Inorder:** Left → Root → Right
  - **Postorder:** Left → Right → Root