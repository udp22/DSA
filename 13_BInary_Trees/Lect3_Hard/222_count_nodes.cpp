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

    int findLeftH(TreeNode* root){
        int left=0;
        while(root){
            left++;
            root=root->left;
        }
        return left;
    }
    int findRightH(TreeNode* root){
        int right=0;
        while(root){
            right++;
            root=root->right;
        }
        return right;
    }

    int solve(TreeNode* root){
        if(!root) return 0;

        int lh=findLeftH(root);
        int rh=findRightH(root);

        if(lh==rh){
            return (1<<lh)-1;
        }

        return 1+solve(root->left)+solve(root->right);

    }

    int countNodes(TreeNode* root) {
    
        return solve(root);
    }
};