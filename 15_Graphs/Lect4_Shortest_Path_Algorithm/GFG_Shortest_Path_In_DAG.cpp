#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
  
    void topoSort(int node,vector<vector<pair<int,int>>>&adj,vector<int>&visited,stack<int>&st){
        visited[node]=1;
        
        for(auto it:adj[node]){
            if(!visited[it.first]){
                topoSort(it.first,adj,visited,st);
            }
        }
        
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        vector<int>visited(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSort(i,adj,visited,st);
            }
        }
        
        vector<int>dist(V);
        
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        
        dist[0]=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node]!=INT_MAX){
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
        
    }
};
