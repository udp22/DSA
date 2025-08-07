#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>>pq;

        // pq.push({0,{0,0}});
        if(grid[0][0]==0){
            pq.push({1,{0,0}});
            dist[0][0]=1;
        } else return -1;

        vector<vector<int>> direc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};


        while(!pq.empty()){
            int dis=pq.front().first;
            int x=pq.front().second.first;
            int y=pq.front().second.second;
            pq.pop();

            for(int i=0;i<8;i++){
                auto dir = direc[i];

                int nx=x+dir[0];
                int ny=y+dir[1];

                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    if(dis+1<dist[nx][ny]){
                        dist[nx][ny]=dis+1;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }

        }

        if(dist[n-1][n-1]==INT_MAX) return -1;

        return dist[n-1][n-1];

    }
};