#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph,vector<int>&visited,vector<int>&pathVis,vector<int>&safe){
        visited[node]=1;
        pathVis[node]=1;

        for(auto it:graph[node]){
            
            if(!visited[it]){
                if(!dfs(it,graph,visited,pathVis,safe)) return false;
            }
            else{
                if(pathVis[it]!=0){
                    return false;;
                }
            }
        }
        safe[node]=1;
        pathVis[node]=0;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>visited(n,0);
        vector<int>pathVis(n,0);
        vector<int>safe(n,0);

        for(int i=0;i<n;i++){
            dfs(i,graph,visited,pathVis,safe);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]){
                ans.push_back(i);
            }   
        }

        return ans;
    }
};