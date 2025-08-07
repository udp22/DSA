#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&visited){
        visited[node]=1;

        for(auto it:isConnected[node]){
            if(!visited[it]){
                dfs(it,isConnected,visited);
            }
        }
    }

    void bfs(int start,vector<vector<int>>&adj,vector<int>&visited){
        queue<int>q;
        q.push(start);
        visited[start]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<int>visited(n+1,0);

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans=0;

        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                bfs(i,adj,visited);
                ans++;
            }
        }

        return ans;
    }
};