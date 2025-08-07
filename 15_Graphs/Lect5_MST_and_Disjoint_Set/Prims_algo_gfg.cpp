#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // int n=adj.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        //{weight,node}
        pq.push({0,0});
        
        vector<int>visited(V,0);
        
        int sum=0;
        
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            if(visited[node]==1) continue;
            visited[node]=1;
            
            sum=sum+wt;
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edgeWt=it[1];
                
                if(!visited[adjNode]){
                    pq.push({edgeWt,adjNode});
                }
            }
            
        }
        
        return sum;
    }
};