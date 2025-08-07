#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(vector<vector<int>>& grid,vector<vector<int>>&visited,queue<pair<int,int>>&q,int &time,int &fresh){

        int m=grid.size();
        int n=grid[0].size();

        int dr[4]={-1,0,0,1};
        int dc[4]={0,1,-1,0};
        
        while(!q.empty()){
            bool tra=false;
            int size=q.size();
            for(int j=0;j<size;j++){
                auto front=q.front();
                q.pop();
                int row=front.first;
                int col=front.second;


                for(int i=0;i<4;i++){
                    int r=row+dr[i];
                    int c=col+dc[i];

                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1 && !visited[r][c]){
                        visited[r][c]=1;
                        fresh--;
                        q.push({r,c});
                        tra=true;
                    }
                }
            }
            if(tra)
                time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        queue<pair<int,int>> q;

        int fresh=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time=0;
        bfs(grid,visited,q,time,fresh);

        if(fresh){
            return -1;
        }
        return time;

    }
};