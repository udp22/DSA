#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if root is null
        if (!root) return nullptr;

        if (key < root->val) {
            // Key lies in left subtree
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            // Key lies in right subtree
            root->right = deleteNode(root->right, key);
        }
        else {
            // Found the node to delete

            // Case 1: Node has no left child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: Node has no right child
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has both children
            // Find inorder predecessor (max in left subtree)
            TreeNode* temp = root->left;
            while (temp->right)
                temp = temp->right;

            // Copy its value to current node
            root->val = temp->val;

            // Delete the inorder predecessor
            root->left = deleteNode(root->left, temp->val);
        }

        return root;
    }
};
