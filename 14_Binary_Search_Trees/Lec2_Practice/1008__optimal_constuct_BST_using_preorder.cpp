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

//using approach 4

class Solution {
public:
    TreeNode* build(vector<int>&preorder,int& i,int bound){
        if(i==preorder.size() || preorder[i]>bound) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};