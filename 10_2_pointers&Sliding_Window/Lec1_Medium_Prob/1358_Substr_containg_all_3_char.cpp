#include<bits/stdc++.h>
using namespace std;

//using 2 pointer and slinding window

class Solution {
public:

    int solve(string s,int k){
        int n=s.length();
        int cnt=0;
        unordered_map<int,int> mpp;
        int l=0,r=0;
        while(r<n){
            mpp[s[r]]++;
            
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }

            cnt=cnt+(r-l+1);
            r++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) {
        //no of substrings having at most 3 diff chars - no of string having at most 2 diff chars

        return solve(s,3)-solve(s,2);
    }
};