#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,stack<int>&st){
        visited[node]=1;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        
        st.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>visited(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};