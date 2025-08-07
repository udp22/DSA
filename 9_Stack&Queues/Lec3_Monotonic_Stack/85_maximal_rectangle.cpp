#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int pse=INT_MIN;
        int nse = INT_MIN;

        vector<int> hist(m,0);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            stack<int>st;
            for(int j=0;j<m;j++){
                hist[j] = (matrix[i][j] == '1' ? hist[j] + 1 : 0);
            }
            for(int j=0;j<m;j++){

                while(!st.empty() && hist[j]<hist[st.top()]){
                    int ht = hist[st.top()];
                    st.pop();
                    if(st.empty()){
                        pse=-1;
                    }
                    else{
                        pse=st.top();
                    }
                    nse=j;
                    ans = max(ans,ht*(nse-pse-1));
                }
                st.push(j);
            }

            nse=m;
            while(!st.empty()){
                int ht = hist[st.top()];
                st.pop();
                if(st.empty()){
                    pse=-1;
                }
                else{
                    pse=st.top();
                }
                ans=max(ans,ht*(nse-pse-1));
            }

            
        
            
        }

        return ans;
    }
};