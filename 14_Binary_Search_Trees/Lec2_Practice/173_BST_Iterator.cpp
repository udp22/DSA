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

class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }
    
    int next() {
        if(st.size()>0){
            TreeNode* temp=st.top();
            st.pop();
            TreeNode* curr=temp->right;
            while(curr){
                st.push(curr);
                curr=curr->left;
            }

            return temp->val;
        }

        return -1;
    }
    
    bool hasNext() {
        
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */