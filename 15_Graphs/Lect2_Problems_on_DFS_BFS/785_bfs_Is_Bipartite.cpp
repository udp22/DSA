#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(vector<vector<int>>& graph,vector<int>&color,int node){
        queue<int>q;
        q.push(node);
        color[node]=0;

        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:graph[front]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[front];
                }
                else{
                    if(color[front]==color[it]) return false;
                }
            }

        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        //bipartite is a graph which can be colored in exactly two colours such that no two adjacent nodes
        // have same color
        
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1)
            if(!bfs(graph,color,i)) return false;
        }

        return true;

    }
};