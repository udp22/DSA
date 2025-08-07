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

    int maxDepth(TreeNode* root,int& diameter){
        if(root==nullptr) return 0;

        int lh=maxDepth(root->left,diameter);
        int rh=maxDepth(root->right,diameter);

        diameter=max(diameter,lh+rh);

        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        maxDepth(root,diameter);

        return diameter;
    }
};