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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        q.push(root);
        bool flag=true;

        while(!q.empty()){
            int size=q.size();
            vector<int>level;

            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            if(flag){
                ans.push_back(level);
                flag=false;
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
                flag=true;
            }
        }

        return ans;
    }
};