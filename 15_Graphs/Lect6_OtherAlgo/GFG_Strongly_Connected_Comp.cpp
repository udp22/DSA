#include <bits/stdc++.h>
using namespace std;

//Position this line where user code will be pasted.
class Solution {
private:
    void dfs(int node,vector<vector<int>> &adj,vector<int>&visited,stack<int>&st){
        
        visited[node]=1;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node,vector<vector<int>> &adjT,vector<int>&visited){
        
        visited[node]=1;
        
        for(auto it:adjT[node]){
            if(!visited[it]){
                dfs2(it,adjT,visited);
            }
        }
        
    }
    
    
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int>visited(n,0);
        stack<int>st;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        vector<vector<int>>adjT(n);
        
        for(int i=0;i<adj.size();i++){
            visited[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!visited[node]){
                dfs2(node,adjT,visited);
                scc++;
            }
        }
        
        return scc;
    }
};