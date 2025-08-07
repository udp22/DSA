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

    bool solve(TreeNode* root,long long minr,long long maxr){
        if(root==nullptr) return true;

        if(root->val<=minr || root->val>=maxr){
            return false;
        }

        bool left=solve(root->left,minr,root->val);
        if(!left) return false;

        bool right=solve(root->right,root->val,maxr);
        if(!right) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
