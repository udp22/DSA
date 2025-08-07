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

    TreeNode* findTarget(TreeNode* root,int start){
        if(root==nullptr) return root;
        
        if(root->val==start) return root;
        
        TreeNode* left=findTarget(root->left,start);
        if(left) return left;
        
        return findTarget(root->right,start);
    }
    
    
    void parentConnect(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_map){
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            
            if(front->left){
                q.push(front->left);
                parent_map[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                parent_map[front->right]=front;
            }
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* tg=findTarget(root,start);
        
        unordered_map<TreeNode*,TreeNode*>parent_map;
        parentConnect(root,parent_map);
        
        unordered_map<TreeNode*,bool>visited;
        
        queue<TreeNode*>q;
        q.push(tg);
        visited[tg]=true;
        
        int burn=0;
        
        
        while(!q.empty()){
            burn++;
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                
                if(parent_map[front] && !visited[parent_map[front]]){
                    q.push(parent_map[front]);
                    visited[parent_map[front]]=true;
                }
                
            }
            
            
        }
        
        return burn-1;
    }
};