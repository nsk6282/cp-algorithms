#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int src){
    vector<pii> adj[n];
    for(auto it:edge){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int> dis(n,1e9);
    dis[src]=0;
    set<pii> s;
    s.insert({0,src});
    while(!s.empty()){
        auto curr = *s.begin();
        s.erase(s.begin());
        int nodeDis = curr.first,node = curr.second;
        for(auto it:adj[node]){
            int adjnode = it.first,adjDis = it.second;
            if(dis[adjnode]>nodeDis + adjDis){
                dis[adjnode] = nodeDis + adjDis;
                s.insert({nodeDis + adjDis,adjnode});
            }
        }
    }
    return dis;
}