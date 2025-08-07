#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(n==1 && m==1 ) return 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,-1,0,1};

        while(!pq.empty()){
            auto front=pq.top();
            int diff=front.first;
            int x=front.second.first;
            int y=front.second.second;
            pq.pop();

            if(x==n-1 && y==m-1) return diff;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newEffort=max(abs(heights[x][y]-heights[nx][ny]),diff);
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }

        return -1;
    }
};