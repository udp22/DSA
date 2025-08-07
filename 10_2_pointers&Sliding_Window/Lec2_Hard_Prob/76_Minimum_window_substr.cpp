#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();

        if(n > s.size())    return "";

        // unordered_map<char,int>mpp;
        vector<int>mpp(256,0);
        for(int i=0;i<n;i++){
            mpp[t[i]]++;
        }
        int minLen=INT_MAX;
        int startInd=-1;

        int l=0,r=0;
        int cnt=0;

        while(r<m){
            if(mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt==n){
                if((r-l+1)<minLen){
                    minLen=r-l+1;
                    startInd=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt--;
                }
                l++;
            }

            r++;
        }

        if(startInd<0) return "";
        return s.substr(startInd,minLen);
        
    }
};