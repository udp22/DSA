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

// Function to increment the left subtree
void increment(Node* cur, int diff)  { 

    // If left child is not 
    // nullptr then increment it
    if(cur->left != nullptr) { 
        cur->left->data = cur->left->data + diff; 
    
        // Recursively call to fix 
        // the descendants of Node->left 
        increment(cur->left, diff); 
    } 

    // Else increment right child 
    else if (cur->right != nullptr) { 
        cur->right->data = cur->right->data + diff; 
    
        // Recursively call to fix 
        // the descendants of Node->right 
        increment(cur->right, diff); 
    } 
} 

// Function to modify a tree 
// to hold children sum property
void convertTree(Node* cur) {

    // If tree is empty or it's a 
    // leaf Node then return true
    if (cur == nullptr || (cur->left == nullptr && 
        cur->right == nullptr)) 
        return; 
        
        // convert left and right subtrees first
        convertTree(cur->left); 
        convertTree(cur->right); 
        
    int leftData = 0, rightData = 0;

    // update left and right child data
    if (cur->left != nullptr) 
        leftData = cur->left->data; 

    if (cur->right != nullptr) 
        rightData = cur->right->data; 

    // get the diff of Node's data and children sum
    int diff = leftData + rightData - cur->data; 

    // if Node's children sum is 
    // greater than the Node's data
    if (diff > 0) 
        cur->data = cur->data + diff; 

    // else if Node's data is greater than
    // children sum then increment subtree
    else if (diff < 0) 
        increment(cur, abs(diff));
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