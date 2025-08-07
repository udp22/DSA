#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>hash(26,0);

        int l=0,r=0;
        int maxF=0;
        int maxLen=0;

        while(r<n){
            hash[s[r]-'A'] = hash[s[r]-'A']+1;
            maxF=max(maxF,hash[s[r]-'A']);

            if(r-l+1 - maxF>k){
                hash[s[l]-'A']--;
                l++;
            }

            if(r-l+1-maxF<=k){
                maxLen=max(maxLen,r-l+1);
            }

            r++;
        }

        return maxLen;
    }
};