#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  int delrow[4]={0,1,0,-1};
  int delcol[4]={1,0,-1,0};
  
    void dfs(vector<vector<int>>& grid,set<vector<pair<int,int>>>&st,vector<pair<int,int>>&vec,int row,int col,vector<vector<int>> &visited,int prow,int pcol){
        int n=grid.size();
        int m=grid[0].size();
        
        visited[row][col]=1;
        
        vec.push_back({row-prow,col-pcol});
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                dfs(grid,st,vec,nrow,ncol,visited,prow,pcol);
            }
        }
        
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>>st;
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>vec;   
                    dfs(grid,st,vec,i,j,visited,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};
