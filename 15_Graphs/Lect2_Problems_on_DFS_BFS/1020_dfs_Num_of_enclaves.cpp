#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    void dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        visited[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid,visited,nrow,ncol);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(!visited[i][j] && grid[i][j]==1){
                        dfs(grid,visited,i,j);
                    }
                }
            }
        }
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans++;
                }
            }
        }

        return ans;
    }
};