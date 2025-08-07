#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int>topo;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            topo.push_back(front);
            
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo;
    }
};