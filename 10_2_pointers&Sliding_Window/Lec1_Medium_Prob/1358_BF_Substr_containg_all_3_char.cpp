#include<bits/stdc++.h>
using namespace std;

//Brute force

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            int arr[3]={0};
            for(int j=i;j<n;j++){
                arr[s[j]-'a']=1;
                if((arr[0]+arr[1]+arr[2])==3){
                    cnt+=(n-j);
                    break;
                }
            }
        }

        return cnt;
    }
};