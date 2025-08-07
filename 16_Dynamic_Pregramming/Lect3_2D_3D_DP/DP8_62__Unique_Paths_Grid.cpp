#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(i+1,j,m,n,dp);
        int down=solve(i,j+1,m,n,dp);

        return dp[i][j]=right+down;
        
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        //memoization
        // return solve(0,0,m,n,dp);

        //tabulation
        // dp[0][0]=1;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) dp[0][0]=1;
        //         else{
        //             int up=0,left=0;
        //             if(i>0) up=dp[i-1][j];
        //             if(j>0) left=dp[i][j-1];
        //             dp[i][j]=up+left;
        //         }
        //     }
        // }

        // return dp[m-1][n-1];

        //space optimization

        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }

        return prev[n-1];

    }
};