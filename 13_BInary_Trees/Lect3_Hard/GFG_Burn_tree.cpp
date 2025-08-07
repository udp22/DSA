#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    Node* findTarget(Node* root,int target){
        if(root==nullptr) return root;
        
        if(root->data==target) return root;
        
        Node* left=findTarget(root->left,target);
        if(left) return left;
        
        return findTarget(root->right,target);
    }
    
    
    void parentConnect(Node* root,unordered_map<Node*,Node*>&parent_map){
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node* front=q.front();
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
    
    int minTime(Node* root, int target) {
        // code here
        Node* tg=findTarget(root,target);
        
        unordered_map<Node*,Node*>parent_map;
        parentConnect(root,parent_map);
        
        unordered_map<Node*,bool>visited;
        
        queue<Node*>q;
        q.push(tg);
        visited[tg]=true;
        
        int burn=0;
        
        
        
        while(!q.empty()){
            bool burnt=false;
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    burnt=true;
                    q.push(front->left);
                    visited[front->left]=true;
                }
                
                if(front->right && !visited[front->right]){
                    burnt=true;
                    q.push(front->right);
                    visited[front->right]=true;
                }
                
                if(parent_map[front] && !visited[parent_map[front]]){
                    burnt=true;
                    q.push(parent_map[front]);
                    visited[parent_map[front]]=true;
                }
                
            }

            if(burnt) {
                burn++;
            }
            
        }
        
        return burn;
        
        
    }
};