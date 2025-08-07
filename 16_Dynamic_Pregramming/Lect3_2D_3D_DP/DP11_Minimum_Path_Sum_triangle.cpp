#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int i,int row,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        
        if(row==triangle.size()-1){
            return triangle[row][i];
        }
        if(dp[row][i]!=-1) return dp[row][i];
        int left=triangle[row][i]+solve(i,row+1,triangle,dp);
        int right=triangle[row][i]+solve(i+1,row+1,triangle,dp);

        return dp[row][i] =  min(left,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(0,0,triangle,dp);

        //tabulation
        // vector<vector<int>>dp(n,vector<int>(m,0));

        // for(int j=0;j<m;j++){
        //     dp[n-1][j]=triangle[n-1][j];
        // }

        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int d=triangle[i][j]+dp[i+1][j];
        //         int dg=triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j]=min(d,dg);
        //     }
        // }

        // return dp[0][0];

        //space optimization

        vector<int>front(m,0),curr(m,0);

        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+front[j];
                int dg=triangle[i][j]+front[j+1];

                curr[j]=min(d,dg);
            }
            front=curr;
        }

        return front[0];
        
    }
};