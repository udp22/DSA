#include<bits/stdc++.h> 
using namespace std;

// Node structure
class Node { 
public:
    int data; 
    Node* left; 
    Node* right; 
    Node(int data) {
        this->data = data; 
        this->left = nullptr; 
        this->right = nullptr;
    }
}; 

// Function to modify a tree 
// to hold children sum property
void convertTree(Node* root) {
    
    // if root is null, return
    if (!root) return;

    // find the left and right child sum
    int childSum = 0;

    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;
    
    // if the root's data is less than 
    // the sum of its children
    if (root->data < childSum) {
        root->data = childSum;
    } 
    
    // if the root's data is greater than
    // the sum of its children
    else if (root->data > childSum) {
        int diff = root->data - childSum;

        // if left child is not null
        if (root->left) 
            root->left->data += diff;
        
        // else if right child is not null
        else if (root->right)
            root->right->data += diff;
    }
    
    // modify the left and right subtree
    convertTree(root->left);
    convertTree(root->right);

    // update the root's data to sum
    // of child node's data
    childSum = 0;

    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;

    // if root is not leaf node
    if(root->left || root->right) 
        root->data = childSum;
}

// prints the inorder traversal of tree
void printInorder(Node* cur)  { 
    if (cur == nullptr) 
        return; 
    
    printInorder(cur->left); 
    cout<<cur->data<<" ";
    printInorder(cur->right); 
} 

int main()  { 
    // construct the binary tree
    /*
        50
       /  \     
      7    2
     / \  / \
    3   5 1  30    */
    
    Node *root = new Node(50); 
    root->left = new Node(7); 
    root->right = new Node(2); 
    root->left->left = new Node(3); 
    root->left->right = new Node(5); 
    root->right->left = new Node(1); 
    root->right->right = new Node(30); 
    printInorder(root);
    cout<<endl;

    convertTree(root); 
    
    printInorder(root); 
    return 0; 
}