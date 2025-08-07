#include <bits/stdc++.h>
using namespace std;

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        set<pair<int,int>>st;
        
        // pq.push({0,src});
        st.insert({0,src});
        
        vector<int>dist(V,INT_MAX);
        
        dist[src]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int edgeW=it.second;
                int adjNode=it.first;
                if(dist[adjNode]>dis+edgeW){
                    if(dist[adjNode]!=INT_MAX){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dis+edgeW;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
        
        
    }
};