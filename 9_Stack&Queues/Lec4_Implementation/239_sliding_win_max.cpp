#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            //used to remove elements when size of deque is greater than window size
            if(!dq.empty() && dq.front()<=i-k){ 
                dq.pop_front();
            }
            //remove smaller elements present in dq
            while(!dq.empty() && nums[dq.back()]<=nums[i]){ 
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
            
        }

        return ans;
    }
};