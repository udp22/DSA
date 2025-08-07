#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int,Node*>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        vector<int>ans;
        if(root==nullptr) return ans;
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(mp.find(front.second)==mp.end()) mp[front.second]=front.first;
            if(front.first->left )q.push({front.first->left,front.second-1});
            if(front.first->right)q.push({front.first->right,front.second+1});
            
        }
        
        
        
        for(auto it:mp){
            ans.push_back(it.second->data);
        }
        
        return ans;
        
    }
};