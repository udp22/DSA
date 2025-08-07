#include<bits/stdc++.h>
using namespace std;


//using two pointers
class Solution {
public:

    int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size();
        int l=0,r=0;

        int oddnums=0;
        int cnt=0;

        while(r<n){
            oddnums+=nums[r]%2;

            while(oddnums>k){
                oddnums-=nums[l]%2;
                l++;
            }

            cnt=cnt+(r-l+1);
            r++;

        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //exactly=k => less that equal to k - less than equal to k-1

        return solve(nums,k)-solve(nums,k-1);
    }
};