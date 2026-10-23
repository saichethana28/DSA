# Binary Tree Inorder Traversal

## Problem Statement

Given the root of a binary tree, return its inorder traversal.

Inorder traversal follows **Left → Root → Right**.

### Examples

```text
Input: root = [1,null,2,3]
Output: [1,3,2]
```

```text
Input: root = [1,2,3]
Output: [2,1,3]
```

## Observations

- Inorder traversal visits the left subtree first.
- Then visit the root node.
- Finally, visit the right subtree.
- Use a stack to simulate recursion iteratively.
- Keep moving left until reaching `NULL`, then process the node and move right.

## Brute Force

- Use recursion to traverse the tree.
- Recursively visit the left subtree.
- Add the root value to the result.
- Recursively visit the right subtree.

### Complexity

- **Time:** `O(N)` — visit every node once.
- **Space:** `O(H)` — recursion stack, where `H` is the tree height.

## Optimal Approach

- Use a stack to store nodes while moving left.
- When the current node becomes `NULL`, pop the top node.
- Add its value to the result and move to its right child.
- Continue until the current node is `NULL` and the stack is empty.

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;

        while(true) {
            if(node != NULL) {
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty())
                    break;

                node = st.top();
                st.pop();

                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};
```

### Complexity

- **Time:** `O(N)` — each node is pushed and popped once.
- **Space:** `O(H)` auxiliary space, where `H` is the tree height; worst case `O(N)`.

## Key Takeaways

- **Pattern:** Binary Tree Traversal + Stack.
- Inorder = **Left → Root → Right**.
- Keep pushing nodes while moving left.
- After popping and processing a node, move to its right child.
- Iterative traversal avoids recursive function calls.