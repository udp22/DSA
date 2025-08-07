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

    int PathSum(TreeNode* root,int &psum){
        if(root==nullptr) return 0;
        
        int lsum=max(0,PathSum(root->left,psum));
        int rsum=max(0,PathSum(root->right,psum));
        
        psum=max(psum,root->val+lsum+rsum);


        return root->val+max({lsum,rsum});
    }

    int maxPathSum(TreeNode* root) {
        int psum=-1e3;
        PathSum(root,psum);

        return psum;
    }
};