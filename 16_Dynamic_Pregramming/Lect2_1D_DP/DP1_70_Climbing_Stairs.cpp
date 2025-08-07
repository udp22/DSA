#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memoization(int n,vector<int>&dp){

        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=memoization(n-1,dp)+memoization(n-2,dp);
    }

    int tabulation(int n,vector<int>&dp){

        if(n<=2) return n;

        int prev=2;
        int prev2=1;

        dp[0]=1;
        dp[1]=2;

        for(int i=3;i<=n;i++){
            
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n-1];
    
    }

    int space_optimization(int n){

        if(n<=2) return n;

        int prev=2;
        int prev2=1;

        for(int i=3;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }

        return prev;
    
    }

    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return memoization(n,dp);
    }
};