#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0,cnt=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.find(sum-goal)!=mpp.end()){
                cnt+=mpp[sum-goal];
            }
            mpp[sum]++;
        }

        return cnt;
    }
};