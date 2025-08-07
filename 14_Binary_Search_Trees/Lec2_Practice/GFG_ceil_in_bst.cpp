#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int findCeil(Node* root, int input) {
    // Your code here
    int c=-1;
    
    while(root){
        
        if(root->data==input){
            c = root->data;
            return c;
        }
        
        if(input>root->data){
            root=root->right;
        }
        else{
            c = root->data;
            root=root->left;
        }
    }
    
    return c;
}