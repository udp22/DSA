#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(int n){
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        DisjointSet ds(n*m);

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;  
                int node=i*m + j;

                for(int k=0;k<4;k++){
                    int adjrow=i+delrow[k];
                    int adjcol=j+delcol[k];

                    if(adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<m && grid[adjrow][adjcol]==1){
                        int adjnode=adjrow*m + adjcol;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }
        
        int maxSize=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
                set<int>st;
                for(int k=0;k<4;k++){
                    int adjrow=i+delrow[k];
                    int adjcol=j+delcol[k];

                    if(adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<m && grid[adjrow][adjcol]==1){
                        int parent = ds.findPar(adjrow*m + adjcol);
                        st.insert(parent);
                    }
                }

                int size=1;
                for(auto it:st){
                    size+=ds.size[it];
                }
                maxSize=max(size,maxSize);
            }
        }

        for(int i=0;i<n*m;i++){
            maxSize=max(maxSize,ds.size[ds.findPar(i)]);
        }
        return maxSize;
    }
};