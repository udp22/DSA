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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;

        if(root==nullptr){
            TreeNode* nn=new TreeNode(val);
            return nn;
        }

        while(curr){

            if(!curr->left && !curr->right){
                break;
            }

            if(curr->val >val){
                if(curr->left) curr=curr->left;
                else break;
            }
            else{
                if(curr->right)curr=curr->right;
                else break;
            }
        }

        TreeNode* nn=new TreeNode(val);
        if(curr->val>val){
            curr->left=nn;
        }
        else{
            curr->right=nn;
        }

        return root;
    }
};
