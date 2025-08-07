#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftSum=0;
        int rightSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++) leftSum+=cardPoints[i];

        maxSum=leftSum;
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum +=cardPoints[r];
            r--;

            maxSum=max(maxSum,leftSum+rightSum);
        }

        return maxSum;


    }
};