#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>&dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];
    
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int fibTab(int n,vector<int>&dp){
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int main() {

    int n;
    cin>>n;

    vector<int>dp(n+1,-1);

    //Memoization
    // int ans = fib(n,dp);
    // cout<<ans<<endl;

    //Tabulation
    // int ans=fibTab(n,dp);
    // cout<<ans<<endl;

    //Space optimization
    int prev=1;
    int prev2=0;

    for(int i=2;i<=n;i++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }

    cout<<prev<<endl;


    return 0;
}