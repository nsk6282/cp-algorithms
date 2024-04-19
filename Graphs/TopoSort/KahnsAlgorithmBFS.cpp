#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //toposort is only possible in directed acyclic graphs (DAG)
    //toposort array created with kahn's algo will yield an incomplete array
    //hence this can be used to detect cycle in directed graphs.
    vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int n) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it:graph){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;

    }

};