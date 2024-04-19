#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, int par,vector<vector<int>>& graph,vector<int>&vis){
        if(par==-1 || vis[par]==2) vis[node]=1;
        else vis[node] = 2;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(!dfs(it,node,graph,vis)) return false;
            }
            else{
                if(it!=par && vis[it]==vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,-1,graph,vis)) return false;
            }
        }
        return true;

    }
};