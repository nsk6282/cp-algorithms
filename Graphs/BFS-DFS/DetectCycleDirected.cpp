#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int par,vector<int> adj[],vector<int> &vis,vector<int> &path){
	vis[node] =1;
	path[node]=1;
	for(auto it:adj[node]){
		if(!vis[it]){
			if(dfs(it,node,adj,vis,path)) return true;
		}
		else{
			if(path[it]) return true;
		}
	}
	path[node]=0;
	return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e){
	// Write your code here
	vector<int> vis(v,0), path(v,0);
	vector<int> adj[v];
	for(auto it:edges){
		adj[it[0]].push_back(it[1]);
	}
	for(int i=0;i<v;i++){
		if(!vis[i]){
			if(dfs(i,-1,adj,vis,path)) return true;
		}
	}
	return false;
}
