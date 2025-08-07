#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int delrow[4]={0,-1,0,1};
    int delcol[4]={-1,0,1,0};

    void dfs(vector<vector<char>>& board,vector<vector<int>>&visited,int row,int col){
        int m=board.size();
        int n=board[0].size();
        visited[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(board,visited,nrow,ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O' && !visited[i][j]){
                    dfs(board,visited,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }
};