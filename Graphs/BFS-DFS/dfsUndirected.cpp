#include <bits/stdc++.h>
using namespace std;
//sc -> o(3n) === O(n)
//tc -> O(V + 2E)
void dfs(int node,vector<int> &vis,vector<int> adj[], vector<int> &ans){
    //asuming 1-based indexing
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,ans);
        }
    }
    return;
}

vector<int> traversal(int n,vector<vector<int>> edges){
    vector<int> adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n+1,0), ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,ans);
        }
    }
    return ans;
}