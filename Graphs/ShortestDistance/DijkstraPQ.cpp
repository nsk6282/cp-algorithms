#include <bits/stdc++.h>
using namespace std;
//tc-> O( Elog(V) );
// not designed for negative weights and negative cycles
typedef pair<int,int> pii;
vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int src){
    vector<pii> adj[n];
    for(auto it:edge){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int> dis(n,1e9);
    dis[src]=0;
    priority_queue<pii ,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [nodeDis,node] = pq.top();
        pq.pop();
        for(auto [adjnode,adjDis]:adj[node]){
            if(dis[adjnode]>nodeDis + adjDis){
                dis[adjnode] = nodeDis + adjDis;
                pq.push({nodeDis + adjDis,adjnode});
            }
        }
    }
    return dis;

}