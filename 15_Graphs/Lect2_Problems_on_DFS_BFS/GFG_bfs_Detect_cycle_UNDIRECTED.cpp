#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void bfs(vector<vector<int>>&adj,int node,vector<int>&visited,bool &ans){
        queue<pair<int,int>>q;
        q.push({node,-1});
        visited[node]=1;
        
        while(!q.empty()){
            auto n=q.front();
            int front=n.first;
            int parent=n.second;
            q.pop();
            
            for(auto i:adj[front]){
                if(visited[i] && i!=parent){
                    ans=true;
                    return ;
                }
                else if(!visited[i]){
                    q.push({i,front});
                    visited[i]=1;
                }
            }
        }
        
        
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(V);
        
        bool ans=false;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(adj,i,visited,ans);
            }
            if(ans){
                break;
            }
        }
        
        if(ans) return true;
        return false;
        
        
        
    }
};