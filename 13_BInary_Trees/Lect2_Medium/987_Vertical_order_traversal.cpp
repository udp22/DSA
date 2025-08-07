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

    static bool customCompare(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }

    void preorder(map<int,vector<pair<int,int>>>& mpp,TreeNode* root,int order,int row){
        if(root==nullptr){
            return;
        }
        mpp[order].push_back({row,root->val});
        preorder(mpp,root->left,order-1,row+1);
        preorder(mpp,root->right,order+1,row+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mpp;
        preorder(mpp,root,0,0);

        vector<vector<int>> res;

        for(auto&[key,value]:mpp){
            //value -> vector<pair<row,root->val>>
            sort(value.begin(), value.end(),customCompare);
            int size=value.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                level.push_back(value[i].second);
            }

            res.push_back(level);
        }

        return res;

    }
};