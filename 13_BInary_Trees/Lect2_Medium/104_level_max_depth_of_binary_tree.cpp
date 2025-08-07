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
    int maxDepth(TreeNode* root) {
        int h=0;
        queue<TreeNode*>q;
        if(root==nullptr) return h;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            h++;
            while(size>0){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
                size--;
            }
        }

        return h;
    }
};