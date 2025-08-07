#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxLen=0;
        int l=0,r=0;

        map<int,int>ump;

        while(r<n){
            ump[fruits[r]]++;

            if(ump.size()>2 ){
                ump[fruits[l]]--;
                if(ump[fruits[l]]==0) ump.erase(fruits[l]);
                l++;
            }

            maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};