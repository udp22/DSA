#include <bits/stdc++.h>
using namespace std;

class Solution {
    
  private:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,int parent,bool& ans){
        visited[node]=1;
        
        for(auto i:adj[node]){
            if(!visited[i]){
                if(dfs(i,adj,visited,node,ans)) return true;
            }
            else if(i!=parent){
                return true;
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //dfs
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(V,0);
        bool ans = false;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,-1,ans)) return true;
            }
        }
        
        return false;
    }
};