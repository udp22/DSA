#include<bits/stdc++.h>
using namespace std;


// 1004. Max Consecutive Ones III

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int maxLen=0;

        while(r<n){
            if(nums[r]==0){
                k--;
            }
            if(k<0){
                if(nums[l]==0) k++;
                l++;
            }

            if(k>=0)
                maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};