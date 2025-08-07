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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;

        queue<pair<TreeNode*,long long>>q;

        q.push({root,0});

        int width=INT_MIN;

        while(!q.empty()){
            int size=q.size();
            long long offset=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int currId=q.front().second-offset;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=currId;  //intresting steps
                if(i==size-1) last=currId;
                if(node->left) q.push({node->left,(long long)2*currId+1});
                if(node->right)q.push({node->right,(long long)2*currId+2});
            }

            width=max(width,last-first+1);

        }

        return width;
    }
};