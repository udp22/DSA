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

class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int f=-1;
        
        while(root){
            if(root->data==x){
                return x;
            }
            
            if(x>root->data){
                f=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        
        return f;
    }
};