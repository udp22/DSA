#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    //     if(i==0) return matrix[i][j];
    //     int m=matrix[0].size();
    //     int l=INT_MAX,c=INT_MAX,r=INT_MAX;
    //     if(dp[i][j]!=1e9) return dp[i][j];
    //     if(j>0) l=matrix[i][j]+solve(i-1,j-1,matrix,dp);
    //     c=matrix[i][j]+solve(i-1,j,matrix,dp);
    //     if(j<m-1) r=matrix[i][j]+solve(i-1,j+1,matrix,dp);

    //     return dp[i][j]= min(l,min(c,r));
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        // int ans=INT_MAX;
        // int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,1e9));
        // for(int i=0;i<matrix[0].size();i++){
        //     ans=min(ans,solve(n-1,i,matrix,dp));
        // }

        // return ans;

        //tabulation
        // int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,1e9));

        // for(int i=0;i<n;i++){
        //     dp[0][i]=matrix[0][i];
        // }

        // for(int i=1;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         int l=INT_MAX,c=INT_MAX,r=INT_MAX;
        //         if(j>0) l=matrix[i][j]+dp[i-1][j-1];
        //                 c=matrix[i][j]+dp[i-1][j];
        //         if(j<n-1) r=matrix[i][j]+dp[i-1][j+1];

        //         dp[i][j]=min(l,min(c,r));
        //     }
        // }
        
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,dp[n-1][i]);
        // }

        // return ans;

        //space optimization
        int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,1e9));
        vector<int>prev(n,0),curr(n,0);

        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int l=INT_MAX,c=INT_MAX,r=INT_MAX;
                if(j>0) l=matrix[i][j]+prev[j-1];
                        c=matrix[i][j]+prev[j];
                if(j<n-1) r=matrix[i][j]+prev[j+1];

                curr[j]=min(l,min(c,r));
            }
            prev=curr;
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,prev[i]);
        }

        return ans;


    }
}; 