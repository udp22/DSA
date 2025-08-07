#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());

        sort(s.begin(),s.end());
        

        int j=0;
        int m=s.size();
        if(m==0) return 0;
        int cnt=0;
        int i=0;
        int n=g.size();
        while(i<g.size() && j<m){
            
            if(j<m && g[i]<=s[j]){
                cnt++;
                j++;
                i++;
            }

            else if(s[j]<g[i]) j++;

            if(j>=m || i>=n){
                break;
            }
        }

        return cnt;
    }
};