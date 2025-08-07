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

    void preorder(TreeNode* root, string path, vector<string>& ans) {
    if (root == nullptr) return;

    if (!path.empty()) path += "->";
    path += to_string(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(path);
        return;
    }

    preorder(root->left, path, ans);
    preorder(root->right, path, ans);
}

    vector<string> binaryTreePaths(TreeNode* root) {
         string temp="";
         vector<string>ans;
         preorder(root,temp,ans);

         return ans;
    }
};
