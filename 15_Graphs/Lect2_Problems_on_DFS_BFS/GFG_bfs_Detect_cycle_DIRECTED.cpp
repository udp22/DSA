#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            auto x =edges[i];
            adj[x[0]].push_back(x[1]);
        }
        
        
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(cnt<V) return true;
        
        return false;
        
        
    }
};