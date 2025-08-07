#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>ans;

        vector<int>indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(ans.size()==numCourses){
            return ans;
        }


        return {};

    }
};