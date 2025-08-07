#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis,int i, int j,int m,int n){
        queue<pair<int,int>> q;
        if(grid[i][j]=='0') return;
        q.push({i,j});
        vis[i][j]=1;

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            int r=front.first;
            int s=front.second;

            for(int k=0;k<4;k++)
            {
                int newrow=r+delrow[k];
                int newcol=s+delcol[k];

                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]=='1' && !vis[newrow][newcol])
                {
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            } 
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,vis,i,j,m,n);
                } 
            }
        }

        return cnt;
    }
};