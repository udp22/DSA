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
    //morris traversal

    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* curr=root;
        int cnt=0;
        int ans=-1;
        while(curr){
            if(curr->left){
                TreeNode* temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==nullptr){
                    temp->right=curr;
                    //do postorder traversal things
                    curr=curr->left;
                }
                else{
                    temp->right=nullptr;
                    
                    //do inorder traversal things
                    cnt++;
                    if(cnt==k){
                        ans=curr->val;
                    }
                    curr=curr->right;
                    
                }
                
            }
            else{
                cnt++;
                if(cnt==k){
                    ans=curr->val;
                }
                curr=curr->right;
            }
        }

        return ans;
    }
};