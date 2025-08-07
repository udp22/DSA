#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>ans(m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n ;j++){
                ans[j] = ans[j]+mat[i][j];
            }
        }
        
        int cnt=0;
        int index=-1;
        
        for(int j=0;j<m;j++){
            if (ans[j] == n) {
                // And should not know anyone else
                bool knowsSomeone = false;
                for (int k = 0; k < n; k++) {
                    if (k != j && mat[j][k] == 1) {
                        knowsSomeone = true;
                        break;
                    }
                }
                if (!knowsSomeone) return j;
            }
        }
        
        // if(cnt==1) return index;
        // else{
            return -1;
        // }
    }
};