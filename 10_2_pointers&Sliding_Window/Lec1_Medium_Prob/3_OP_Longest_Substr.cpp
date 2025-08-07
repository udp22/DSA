#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n<1) return 0;
        int maxLen=0;
        //can also use hashset hash[256]={-1}
        unordered_map<char,int>mp;
        int l=0,r=0;
        while(r<n){
            
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l)
                    l=mp[s[r]]+1;  
            }
            mp[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};