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

//using approach 1

class Solution {
public:

    TreeNode* solve(vector<int>&preorder,int start,int end){
        if(start>end){
            return nullptr;
        }

        TreeNode* root=new TreeNode(preorder[start]);

        int i=start+1;
        while(i<=end && preorder[i]<=preorder[start]){
            i=i+1;
        }
        root->left=solve(preorder,start+1,i-1);
        root->right=solve(preorder,i,end);

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        TreeNode* root=solve(preorder,0,n-1);

        return root;
    }
};