#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<int> adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dis(n,1e9);
    dis[src]=0;
    queue<pair<int,int>> q;
    q.push({0,src});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int nodeDis = curr.first, node  = curr.second;
        for(auto adjNode:adj[node]){
            if(dis[adjNode]>nodeDis + 1){
                dis[adjNode] = nodeDis +1;
                q.push({nodeDis +1,adjNode});
            }
        }
    }
    for(auto &it:dis){
        if(it==1e9) it=-1;
    }
    return dis;
}