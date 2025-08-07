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

//single violation means the nodes are adjacent in inorder traversal
//two violation means nodes are not adjacent in inorder traversal

class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        
        inorder(root->left);

        if(prev!=NULL && (root->val)<prev->val){

            //first violation
            if(first==NULL){
                first=prev;
                middle=root;
            }
            //second violation
            else{
                last=root;
            }
        }

        prev=root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;

        prev = new TreeNode(INT_MIN);
        inorder(root);
        
        //check if there are two violations
        if(first && last) swap(first->val,last->val);
        //if single violation
        else if(first && middle) swap(first->val,middle->val);
    }
};