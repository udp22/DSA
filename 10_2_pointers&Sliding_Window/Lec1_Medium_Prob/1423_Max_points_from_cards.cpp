#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();

        int totalSum=accumulate(cardPoints.begin(),cardPoints.end(),0);

        if(k==n) return totalSum;

        int winSize=n-k;
        int minSum=0;
        int sum=0;

        for(int i=0;i<winSize;i++){
            sum+=cardPoints[i];
        }

        minSum=sum;

        for(int i=winSize;i<n;i++){
            sum+=cardPoints[i]-cardPoints[i-winSize];
            minSum=min(minSum,sum);
        }

        return (totalSum-minSum);
    }
};