#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxLen=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            int len=0;
            st.clear();
            for(int j=i;j<n;j++){
                if(st.find(s[j])!=st.end()){
                    break;
                }
                else{
                    st.insert(s[j]);
                    len++;
                }
                maxLen=max(maxLen,len);
            }
        }


        return maxLen;
    }
};