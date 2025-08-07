// #define int long long
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;

        int pse=INT_MIN;
        int nse=INT_MIN;

        int ans=INT_MIN;

        for(int i=0;i<n;i++){

            while(!st.empty() && heights[i]<heights[st.top()]){
                int ht=heights[st.top()];
                nse=i;
                st.pop();
                if(st.empty()){
                    pse=-1;
                }
                else{
                    pse=st.top();
                }

                ans = max(ans,ht*(nse-pse-1));
            }
            st.push(i);
        }
        nse=n;
        while(!st.empty()){

            int ht=heights[st.top()];
            st.pop();
            if(st.empty()){
                pse=-1;
            }
            else{
                pse=st.top();
            }

            ans = max(ans,ht*(nse-pse-1));

        }

        return ans;
    }
};