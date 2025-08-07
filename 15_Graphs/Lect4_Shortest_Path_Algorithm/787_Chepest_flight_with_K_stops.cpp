#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            adj[u].push_back({v,wt});
        }

        //{steps,{node,dist}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(stops>k) continue;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;

                if(cost+edgeWt<dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+edgeWt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

        
    }
};