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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        stack<TreeNode*> st;
        TreeNode* temp;

        vector<int>postorder;

        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }

        }

        return postorder;

    }
};