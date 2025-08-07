#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int>ans;
        if(edges.empty()) return {-1};
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        
        vector<int> parent(n+1,-1);
        parent[1]=1;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;
                
                if(dist[adjNode]>dis + edgeWt){
                    dist[adjNode]=dis+edgeWt;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode],adjNode});
                }
                
            }
        }
        
        vector<int> path;
        int i = n;
        if (parent[n] == -1) return {-1};
        while (parent[i] != i) {
            path.push_back(i);
            i = parent[i];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        // vector<int> ans;
        ans.push_back(dist[n]);
        for (int node : path) ans.push_back(node);
        
        return ans;
    }
};