#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class DisjointSet{
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        parent[node]=findPar(parent[node]);
        return parent[node];
    }

    void unionByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v); 

        if(ulp_v==ulp_u) return;

        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }

    }

    void unionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_v==ulp_u) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
class Solution {
  public:
  static bool cmp(vector<int> &edge1, vector<int> &edge2) {
        return edge1[2] < edge2[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        DisjointSet ds(V);
        
        int ans=0;
        
        sort(edges.begin(), edges.end(), cmp);
        
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            if(ds.findPar(u)!=ds.findPar(v)){
                ans+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return ans;
    }
};