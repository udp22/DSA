#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int ind,vector<int>&nums,vector<int>&dp){

        if(ind==0) return nums[ind];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int take=nums[ind]+solve(ind-2,nums,dp);
        int nottake=0+solve(ind-1,nums,dp);

        return dp[ind]= max(take,nottake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n,-1);
        // return solve(n-1,nums,dp);

        //tabulation

        // dp[0]=nums[0];
        // int neg=0;

        // for(int i=1;i<n;i++){
        //     int take=nums[i];
        //     if(i-2>=0)
        //     take = nums[i]+dp[i-2];
        //     int nottake=0+dp[i-1];

        //     dp[i]=max(take,nottake);

        // }

        // return dp[n-1];

        //space optimization

        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;

            int notTake=0+prev;

            int curri = max(take,notTake);

            prev2=prev;
            prev=curri;
        }

        return prev;
    }
};