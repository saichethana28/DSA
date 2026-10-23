# Binary Tree Postorder Traversal

## Problem Statement
Given the root of a binary tree, return its postorder traversal of node values.

Postorder traversal follows **Left → Right → Root**.

### Examples

**Example 1:**
```text
Input: root = [1,null,2,3]
Output: [3,2,1]
```

**Example 2:**
```text
Input: root = [1,2,3]
Output: [2,3,1]
```

## Observations
- Visit the left subtree first.
- Then visit the right subtree.
- Visit the root node at the end.
- Traversal order: **Left → Right → Root**.
- Postorder can be implemented using recursion, one stack, or two stacks.

## Approach 1: Recursion

- If the node is `NULL`, return.
- Recursively traverse the left subtree.
- Recursively traverse the right subtree.
- Add the root's value to the result.

```cpp
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
```

### Complexity
- **Time:** O(N), where N is the number of nodes.
- **Space:** O(H) for the recursion stack, where H is the tree height; O(N) in the worst case.

## Approach 2: Iterative Using Two Stacks

- Push the root into the first stack.
- Pop a node from the first stack and push it into the second stack.
- Push its left child, then its right child, into the first stack.
- Continue until the first stack is empty.
- Pop all nodes from the second stack to get **Left → Right → Root**.

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();

            st2.push(node);

            if (node->left != NULL)
                st1.push(node->left);

            if (node->right != NULL)
                st1.push(node->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};
```

### Complexity
- **Time:** O(N), as every node is processed once.
- **Space:** O(N) for the two stacks.

## Approach 3: Iterative Using One Stack

- Use a stack to track nodes and a pointer `lastVisited` to track the last processed node.
- Move left while the current node is not `NULL`, pushing nodes onto the stack.
- When the left side is exhausted, inspect the top node.
- If its right subtree exists and has not been visited, traverse the right subtree.
- Otherwise, process the node and pop it.

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = st.top();

                if (node->right != NULL &&
                    lastVisited != node->right) {
                    curr = node->right;
                } else {
                    ans.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};
```

### Complexity
- **Time:** O(N), as each node is visited a constant number of times.
- **Space:** O(H) for the stack; O(N) in the worst case.

## Key Takeaways
- **Postorder = Left → Right → Root.**
- **Recursion:** Visit left, visit right, then process the root.
- **Two stacks:** Reverse the processing order to obtain postorder.
- **One stack:** Use `lastVisited` to determine whether the right subtree has already been processed.
- **Interview tip:** Understand recursion first, then learn the two-stack approach. Practise the one-stack approach after understanding how it tracks visited right subtrees.