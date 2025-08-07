#include<bits/stdc++.h>
using namespace std;

// 1004. Max Consecutive Ones III

class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int p;
        int maxLen=0;
        for(int i=0;i<n;i++){
            int len=0;
            p=k;
            for(int j=i;j<n;j++){
                if(arr[j]==1){
                    len++;
                }
                else if(arr[j]==0 && p>0){
                    len++;
                    p--;
                }
                else{
                    break;
                }
                maxLen=max(len,maxLen);
            }
        }
        
        return maxLen;
    }
};
