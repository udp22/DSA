#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& graph,vector<int>&color,int node,int col){
        color[node]=col;

        for(auto it:graph[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                if(!dfs(graph,color,it,!col)) return false;
            }
            else{
                if(color[it]==color[node]) return false;
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
            if(!dfs(graph,color,i,0)) return false;
        }

        return true;



    }
};