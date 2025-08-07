#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        int cnt=0;

        int l=0,r=0;

        while(r<n){
            mpp[nums[r]]++;

            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }

            if(mpp.size()<=k){
                cnt=cnt+(r-l+1);
            }
            r++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
