#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it.first]){
            dfs(it.first,adj,vis,st);
        }
    }
    st.push(node);
    return;
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    // Write your code here
    vector<pair<int,int>> adj[n];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
    }
    stack<int> st;
    vector<int> dis(n,1e9);
    dis[0]=0;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,adj,vis,st);
    }
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it:adj[node]){
            dis[it.first] = min(dis[it.first],dis[node] + it.second);
        }
    }
    for(auto &it:dis){
        if(it==1e9) it = -1;
    }
    return dis;
}
