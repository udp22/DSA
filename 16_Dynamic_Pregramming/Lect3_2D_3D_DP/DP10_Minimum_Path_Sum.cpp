#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return grid[i][j];
        }

        if(i<0 || j<0 ) return -1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=INT_MAX,left=INT_MAX;
        int p=solve(i-1,j,grid,dp);
        if(p!=-1)
            up=grid[i][j]+p;
        int q=solve(i,j-1,grid,dp);
        if(q!=-1)
            left=grid[i][j]+q;

        return dp[i][j]=min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,grid,dp);

        //tabulation

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i==0 && j==0) dp[i][j]=grid[0][0];
        //         else{
        //             int right=INT_MAX;
        //             int down=INT_MAX;

        //             if(i>0) right=grid[i][j]+dp[i-1][j];
        //             if(j>0) down=grid[i][j]+dp[i][j-1];

        //             dp[i][j]=min(right,down);
        //         }
        //     }
        // }

        // return dp[n-1][m-1];

        //space optimization
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[j]=grid[0][0];
                else{
                    int right=INT_MAX;
                    int down=INT_MAX;

                    if(i>0) right=grid[i][j]+prev[j];
                    if(j>0) down=grid[i][j]+curr[j-1];

                    curr[j]=min(right,down);
                }
            }

            prev=curr;
        }

        return prev[m-1];

    }
};