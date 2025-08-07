#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0){
            return 1;
        }
        if(i>=m || j>=n ||obstacleGrid[i][j]==1 ){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(i+1,j,m,n,dp,obstacleGrid);
        int down=solve(i,j+1,m,n,dp,obstacleGrid);

        return dp[i][j]=right+down;
        
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(0,0,m,n,dp,obstacleGrid);

        //tabulation
        // if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1){
        //     return 0;
        // }
        // else{
        //     dp[0][0]=1;
        // }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) dp[0][0]=1;
        //         else{
        //             int up=0,left=0;
        //             if(i>0 && obstacleGrid[i-1][j]==0) up=dp[i-1][j];
        //             if(j>0 && obstacleGrid[i][j-1]==0) left=dp[i][j-1];
        //             if(obstacleGrid[i][j]==0)
        //                 dp[i][j]=up+left;
        //         }
        //     }
        // }

        // return dp[m-1][n-1];

        //space optimization
        vector<int>prev(n,0);
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        else{
            prev[0]=1;
        }

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[0]=1;
                else{
                    int up=0,left=0;
                    if(i>0 && obstacleGrid[i-1][j]==0) up=prev[j];
                    if(j>0 && obstacleGrid[i][j-1]==0) left=curr[j-1];
                    if(obstacleGrid[i][j]==0)
                        curr[j]=up+left;
                }
            }
            prev=curr;
        }

        return prev[n-1];



    }
};