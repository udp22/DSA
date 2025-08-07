#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node]=2;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited)) return true;
            }
            else{
                if(visited[it]==2){
                    return true;
                }
            }
        }
        
        visited[node]=1;
        
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //dfs
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            auto x =edges[i];
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited)) return true;
            }
        }
        
        return false;
    }
};