#include <bits/stdc++.h>
using namespace std;
/*
bridges are those edges on whose removal the graph breaks down into multiple components.
 we will use two arrays:-
1) tim[]-> dfs time of insertion
2) low[]->lowest time of insertion among all its adjcent nodes except parent
if(low[it]>tin[node]->> it is a bridge )
*/
void dfs(int node, int par,vector<int> &vis,vector<int> &tin,vector<int> &low,int &time,vector<vector<int>> &ans,vector<int> adj[]){
    vis[node]=1;
    tin[node]=time;
    low[node] = time;
    time++;
    for(auto it:adj[node]){
        if(it==par) continue;
        if(!vis[it]){
            dfs(it,node,vis,tin,low,time,ans,adj);
            low[node] = min(low[node],low[it]);
            if(low[it]>tin[node]){
                ans.push_back({node,it});
            }
        }
        else{
            low[node] = min(low[node],low[it]);
        }

    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    for(auto it:connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> tin(n), low(n),vis(n,0);
    int time =1;
    vector<vector<int>> ans;
    dfs(0,-1,vis,tin,low,time,ans,adj);
    return ans;
}