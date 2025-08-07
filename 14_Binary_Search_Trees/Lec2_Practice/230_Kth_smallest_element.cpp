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

    TreeNode* solve(TreeNode* root,int& k){
        if(root==nullptr) return root;
        
        
        TreeNode* left  = solve(root->left,k);
        if(left) return left;

        k=k-1;
        if(k==0) return root;
        
        TreeNode* right=solve(root->right,k);
        return right;
        
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;

        TreeNode* ans= solve(root,k);
        
        return ans->val;

    }
};