#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pii;
int minimumSpanningTree(vector<vector<int>>& edges, int n){
    int sum=0;
    vector<pair<int,int>> MST;
    vector<pair<int,int>> adj[n];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,{0,-1}});
    //{dis,{node,par}};
    vector<int> vis(n,0);
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int dis = curr.first,node=curr.second.first,par = curr.second.second;
        if(vis[node]) continue;
        vis[node]=1;
        if(par!=-1){
            sum+=dis;
            MST.push_back({node,par});
        }
        for(auto it:adj[node]){
            int adjnode = it.first,adj_dis = it.second;
            if(!vis[adjnode]){
                pq.push({adj_dis,{adjnode,node}});
            }
        }
    }
    return sum;
}