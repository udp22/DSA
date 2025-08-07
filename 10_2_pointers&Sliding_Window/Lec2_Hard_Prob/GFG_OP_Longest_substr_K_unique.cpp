#include<bits/stdc++.h>
using namespace std;

//TC -> O(N)
//SC -> O(256)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int n=s.size();
        int l=0,r=0;
        
        int maxLen=-1;
        
        map<char,int>mpp;
        
        while(r<n){
            mpp[s[r]]++;
            
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            
            if(mpp.size()==k)
                maxLen=max(maxLen,r-l+1);
                
            r++;
        }
        
        return maxLen;
    }
};