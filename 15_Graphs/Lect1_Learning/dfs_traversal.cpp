#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void solve(vector<vector<int>>& adj,vector<int>&visited,vector<int>&res,int node){
        
        visited[node]=1;
        
        res.push_back(node);
        
        for(auto it:adj[node]){
            if(!visited[it]){
                solve(adj,visited,res,it);
            }
        }
        
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<int>visited(V,0);
        int start=0;
        vector<int>res;
        
        solve(adj,visited,res,start);
        
        return res;
    }
};