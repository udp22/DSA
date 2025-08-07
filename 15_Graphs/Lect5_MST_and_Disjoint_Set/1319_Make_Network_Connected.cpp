#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n,0);
        size.resize(n,1);

        for(int i=0;i<n;i++){
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

    void unionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u==ulp_v) return;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        DisjointSet dis(n);
        int cntExtra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(dis.findPar(u)!=dis.findPar(v)){
                dis.unionBySize(u,v);
            }
            else{
                cntExtra++;
            }
        }
        
        int components=0;

        for(int i=0;i<n;i++){
            if(dis.parent[i]==i) components++;
        }
        int ans = components-1;
        return ans;
        // return -1;
    }
};