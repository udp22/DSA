#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer=1;
    
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&visited,vector<int>&tin,vector<int>&low,vector<int>&mark){
        visited[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            
            if(!visited[it]){
                dfs(it,node,adj,visited,tin,low,mark);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        
        if(child>1 && parent==-1){
            mark[node]=1;
        }
        
    }
    
    
    
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>visited(V,0);
        vector<int>tin(V,0);
        vector<int>low(V,0);
        
        vector<int>mark(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i])
            dfs(i,-1,adj,visited,tin,low,mark);
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};