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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool inorder(TreeNode* root,TreeNode*& prev){
        if(root==nullptr) return true;
        
        bool left=inorder(root->left,prev);
        
        if (prev && root->val <= prev->val) {
            return false;
        }
        prev = root;
        
        bool right=inorder(root->right,prev);

        if(!left || !right){
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        return inorder(root,prev);
    }
};