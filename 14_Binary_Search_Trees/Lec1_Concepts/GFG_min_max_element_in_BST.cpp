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
    int findMax(Node *root) {
        // code here
        while(root->right!=nullptr){
            root=root->right;
        }
        
        return root->data;
    }

    int findMin(Node *root) {
        
        // code here
        while(root->left!=NULL){
            root=root->left;
        }
        
        return root->data;
    }
};