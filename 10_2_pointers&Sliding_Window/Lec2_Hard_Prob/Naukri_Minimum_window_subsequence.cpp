#include <bits/stdc++.h>
using namespace std;

// This is a hard problem, because we have to maintain order of sequence
// Can be solved using dp, once dp completed, do it again

string minWindow(string S, string T)
{
	int n=S.size();
    int m=T.size();

    int minLen = INT_MAX;
    string ans="";

    for(int i=0;i<n;i++){

        if(S[i]==T[0]){
            int k=i;
            int j=0;

            while(k<n && j<m){
                if(S[k]==T[j]) j++;
                k++;
            }

            // j has reached end of string T
            if(j==m){
                int end=k-1;
                j--;
                k--;
                
                while(j>=0){
                    if(S[k]==T[j]) j--;
                    k--;
                }

                int start=k+1;
                if(end-start+1<minLen){
                    minLen = end-start+1;
                    ans=S.substr(start,minLen);
                }
            }

        }

    }


    return ans;
}