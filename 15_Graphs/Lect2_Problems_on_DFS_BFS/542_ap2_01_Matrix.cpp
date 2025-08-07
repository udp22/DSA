#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m=mat.size();
        int n=mat[0].size();
		
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.emplace(i,j);
                }
                else if(mat[i][j]==1){
                    mat[i][j]=INT_MAX;
                }
            }
        }

        int row[]={1,0,-1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            auto cell=q.front();q.pop();
            int r=cell.first;
            int c=cell.second;
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr<m && nc<n && nr>=0 && nc>=0 && mat[nr][nc]>mat[r][c]+1){
                    mat[nr][nc]=mat[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};