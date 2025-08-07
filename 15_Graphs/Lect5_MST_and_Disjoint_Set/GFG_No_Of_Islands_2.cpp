#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class DisjointSet{
    vector<int>parent,size;
public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int k=operators.size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        
        DisjointSet ds(n*m);
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        
        vector<int>ans;
        int cnt=0;
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            
            int node=row*m + col;
            if(visited[row][col]){
                ans.push_back(cnt);
                continue;
            }
            
            visited[row][col]=1;
            cnt++;
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                int nnode=nrow*m + ncol;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]){
                    if(ds.findPar(node)!=ds.findPar(nnode)){
                        ds.unionBySize(node,nnode);
                        cnt--;
                    }
                }
            }
            
            
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};
