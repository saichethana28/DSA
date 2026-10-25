# Serialize and Deserialize Binary Tree

## Problem Statement
Design an algorithm to serialize a binary tree into a string and deserialize the string back into the original binary tree.

- **Serialization:** Convert a binary tree into a string representation.
- **Deserialization:** Reconstruct the original binary tree from the serialized string.

The reconstructed tree must have the same structure and node values as the original tree.

## Example

**Input Tree:**
```text
       1
      / \
     2   3
        /
       4
```

**Serialized Output:**
```text
1,2,3,#,#,4,#,#,#,
```

Here, `#` represents a null node.

## Observations
- Level-order traversal (BFS) can serialize the tree.
- A queue maintains the order in which nodes are processed.
- Null children must be represented explicitly using `#` to preserve the tree structure.
- During deserialization, only actual nodes are inserted into the queue.
- Comma-separated tokens can be extracted using `getline()` and converted to integers using `stoi()`.

## Approach

### 1. Serialization
1. If the root is `NULL`, return an empty string.
2. Push the root into a queue.
3. Append the root's value to the string.
4. Process each node using BFS:
   - If its left child exists, append its value and enqueue it.
   - Otherwise, append `#`.
   - Repeat the same process for the right child.
5. Return the serialized string.

### 2. Deserialization
1. If the input string is empty, return `NULL`.
2. Extract the first token and create the root.
3. Push the root into a queue.
4. While the queue is not empty:
   - Remove the front node.
   - Read the next token for its left child.
   - If the token is not `#`, create the left child and enqueue it.
   - Read the next token for its right child.
   - If the token is not `#`, create the right child and enqueue it.
5. Return the reconstructed root.

## Code

```cpp
class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);

        string s = to_string(root->val);
        s += ',';

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    s += to_string(node->left->val);
                    s += ',';
                    q.push(node->left);
                } else {
                    s += "#,";
                }

                if (node->right) {
                    s += to_string(node->right->val);
                    s += ',';
                    q.push(node->right);
                } else {
                    s += "#,";
                }
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        stringstream ss(data);
        string str;

        getline(ss, str, ',');

        if (str.empty()) {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, str, ',')) {
                if (str != "#" && !str.empty()) {
                    TreeNode* leftnode = new TreeNode(stoi(str));
                    node->left = leftnode;
                    q.push(leftnode);
                }
            }

            // Right child
            if (getline(ss, str, ',')) {
                if (str != "#" && !str.empty()) {
                    TreeNode* rightnode = new TreeNode(stoi(str));
                    node->right = rightnode;
                    q.push(rightnode);
                }
            }
        }

        return root;
    }
};
```

## Complexity Analysis

Let `n` be the number of nodes in the binary tree.

- **Serialization**
  - Time Complexity: `O(n)`
  - Auxiliary Space: `O(n)`

- **Deserialization**
  - Time Complexity: `O(n)`
  - Auxiliary Space: `O(n)`

## Key Takeaways
- BFS provides a consistent order for serialization and deserialization.
- Explicit null markers preserve the original tree structure.
- `stringstream` and `getline()` help extract comma-separated tokens.
- Use `stoi()` only on valid integer tokens, not on `#` or empty strings.
- Enqueue only non-null nodes during deserialization.