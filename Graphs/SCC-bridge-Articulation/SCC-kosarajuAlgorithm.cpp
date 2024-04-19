#include <bits/stdc++.h>
using namespace std;
// only for directed graphs
//step-1: sort all edges according to finishing time (using scc)
//step-2: reverse all edges
//step-3: do a dfs to get scc
// all three steps are order of O(V+E)=> tc-> O(V+E);
void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
    return;
}
void scc(int node,vector<int> &vis,vector<int> adj[],vector<int> &temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adj[node]){
        if (!vis[it]) {
            scc(it, vis, adj, temp);
        }
    }
    return;
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    // Write your code here.
    int cnt =0;
    stack<int> st;
    vector<int> vis(n,0);
    vector<int> adj[n], radj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        radj[it[1]].push_back(it[0]);        
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<vector<int>> ans;
    fill(vis.begin(), vis.end(), 0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node]) continue;
        vector<int> temp;
        scc(node,vis,radj,temp);
        ans.push_back(temp);
        cnt++;
    }
    return ans;

}
