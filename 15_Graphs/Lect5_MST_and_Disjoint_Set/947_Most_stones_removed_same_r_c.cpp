#include <bits/stdc++.h>
using namespace std;

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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRows=0;
        int maxCols=0;
        for(auto it:stones){
            maxRows=max(maxRows,it[0]);
            maxCols=max(maxCols,it[1]);
        }

        DisjointSet ds(maxRows+maxCols+1);
        unordered_map<int,int>ump;

        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxRows+1;

            ds.unionBySize(row,col);
            ump[row]=1;
            ump[col]=1;
        }

        int cnt=0;
        for(auto it:ump){
            if(ds.findPar(it.first)==it.first){
                cnt++;
            }
        }

        return n-cnt;

    }
};