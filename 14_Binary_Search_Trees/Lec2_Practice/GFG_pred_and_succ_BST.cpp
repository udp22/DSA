#include <bits/stdc++.h>
using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
    Node* succ(Node* root,int key){
        Node* successor=nullptr;
        while(root){
            if(key>=root->data){
                root=root->right;
            }
            else{
                successor=root;
                root=root->left;
            }
        }
        
        return successor;
    }
    
    Node* pred(Node* root,int key){
        Node* predecessor=nullptr;
        
        while(root){
            if(key<=root->data){
                root=root->left;
            }
            else{
                predecessor=root;
                root=root->right;
                
            }
        }
        
        return predecessor;
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans(2);
        ans[0]=pred(root,key);
        ans[1]=succ(root,key);
        
        return ans;
        
    }
};