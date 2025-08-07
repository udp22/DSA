#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& ans,int iniCol,int newCol){

        if(row<0 || row==ans.size() || col<0 || col==ans[0].size()) return;

        if(ans[row][col]==newCol || ans[row][col]!=iniCol) return;

        ans[row][col]=newCol;

        dfs(row+1,col,ans,iniCol,newCol);
        dfs(row-1,col,ans,iniCol,newCol);
        dfs(row,col+1,ans,iniCol,newCol);
        dfs(row,col-1,ans,iniCol,newCol);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image.size();

        vector<vector<int>> ans = image;

        int iniCol = ans[sr][sc];

        dfs(sr,sc,ans,iniCol,color);

        return ans;

    }
};