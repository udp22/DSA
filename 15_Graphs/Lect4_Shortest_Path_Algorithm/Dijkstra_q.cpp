#include <bits/stdc++.h>
using namespace std;

//Not efficient

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        queue<int>q;
        q.push(src);
        
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[it.first]>dist[node]+it.second){
                    dist[it.first]=dist[node]+it.second;
                    q.push(it.first);
                }
            }
        }
        
        return dist;
    }
};