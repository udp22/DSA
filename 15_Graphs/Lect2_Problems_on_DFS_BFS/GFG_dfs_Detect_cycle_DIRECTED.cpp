#include <bits/stdc++.h>
using namespace std;

// Detect cycle code after this solution code

class Solution {
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		// vector<int> adjRev[V];
        vector<vector<int>>adjRev(V);
        vector<int>indegree(V,0);

		for (int i = 0; i < V; i++) {
			// i -> it
			// it -> i
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};

int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}

//Detect cycle
class Solution1 {
  public:
  
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathVisited){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathVisited)) return true;
            }
            else{
                if(pathVisited[it]!=0){
                    return true;
                }
            }
        }
        
        pathVisited[node]=0;
        
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //dfs
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            auto x =edges[i];
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int>visited(V,0);
        vector<int>pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathVis)) return true;
            }
        }
        
        return false;
    }
};