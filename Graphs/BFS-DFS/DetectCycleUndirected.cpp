#include <bits/stdc++.h>
using namespace std;
class Graph {

public:
    bool bfs(int i, vector<int> adj[],vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr.first,par = curr.second;
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }
                else{
                    if(it!=par) return true;
                }
            }
        }
        return false;
    }
    bool dfs(int node,int par,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,node,adj,vis)) return true;
            }
            else{
                if(it!=par) return true;
            }
        }
        return false;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if (!vis[i]) {
                if(dfs(i,-1, adj, vis)) return true;
            }
        }
        return false;
    }
};