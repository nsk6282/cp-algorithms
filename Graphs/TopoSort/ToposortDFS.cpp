#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //toposort is only possible in directed acyclic graphs (DAG)
    void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
        // Write your code here!
        vector<int> adj[nodes];
        stack <int> st;
        for(auto i:graph){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(nodes,0);
        for(int i=0;i<nodes;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }

};