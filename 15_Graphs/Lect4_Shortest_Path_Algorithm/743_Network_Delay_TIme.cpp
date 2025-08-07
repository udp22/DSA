#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }


        // queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //{time,node}
        pq.push({0,k});
        vector<int>time(n+1,INT_MAX);
        time[k]=0;

        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(time[adjNode]>t+wt){
                    time[adjNode]=t+wt;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }

        int ans=INT_MIN;

        for(int i=1;i<=n;i++){
            ans=max(ans,time[i]);
            if(time[i]==INT_MAX) return -1;
        }

        return ans;

    }
};