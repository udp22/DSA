#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n<1) return 0;
        int maxLen=0;
        unordered_set<int>st;
        char prevChar=s[0];
        int l=0,r=0;
        while(r<n){
            
            while (st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};