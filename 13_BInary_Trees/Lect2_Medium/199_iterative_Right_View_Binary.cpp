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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;

        map<int,TreeNode*>mp;
        queue<pair<TreeNode*,int>> q;   
        q.push({root,0});

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode* temp=front.first;
            int order=front.second;

            mp[order]=temp;

            if(temp->left) q.push({temp->left,order+1});
            if(temp->right)q.push({temp->right,order+1});

        }

        for(auto it:mp){
            ans.push_back(it.second->val);
        }

        return ans;
    }
};