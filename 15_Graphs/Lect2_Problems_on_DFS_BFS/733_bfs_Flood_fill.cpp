#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> modImg=image;
        int m=image.size();
        int n=image[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));
        int startCol=modImg[sr][sc];
        modImg[sr][sc]=color;
        visited[sr][sc]=1;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int row=front.first;
            int col=front.second;

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && modImg[nrow][ncol]==startCol){
                    q.push({nrow,ncol});
                    modImg[nrow][ncol]=color;
                    visited[nrow][ncol]=1;
                }
            }
        }

        return modImg;
    }
};