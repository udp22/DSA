#include<bits/stdc++.h>
using namespace std;

//using prefixsum and map concept

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int oddCount=0,cnt=0;

        for(int i=0;i<nums.size();i++){
            oddCount+=(nums[i]%2);
            if(mpp.find(oddCount-k)!=mpp.end()){
                cnt+=mpp[oddCount-k];
            }
            mpp[oddCount]++;
        }

        return cnt;
    }
};