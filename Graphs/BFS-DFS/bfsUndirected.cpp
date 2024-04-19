#include <bits/stdc++.h>
using namespace std;
//sc -> o(3n) === O(n)
//tc -> O(V + 2E)
void BFS(int n,vector<vector<int>> edges){
    //asuming 1-based indexing
    vector<int> adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    queue<int> q;
    vector<int> vis(n+1,0);
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int node = q.front();q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return;
}