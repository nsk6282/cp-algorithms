#include <bits/stdc++.h>

using namespace std;
//used to detect negative cycles and used to find shortest distances with negative weights
// for undirected graphs make sure you count edge bothways(2times u->v and v->u)
//Relax all the edges n-1 times using distance array, 
// relaxation means if(dis[u]+wt<dis[v]) dis[v] = dis[u]+wt;
// why n-1 times? because the src node's edge may be at the end and atmax you need n-1 relaxations to reach all nodes
// in presence of negative cycle, the distance keep decreasing, so in at nth iteartion also if the distance decreases
// there is an negative cycle.
// tc -> O(V*E);
vector<int> bellmonFord(int n, int src, vector<vector<int>> &edges) {
    vector<int> dis(n+1,1e9);
    dis[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u]!=1e9 && dis[v]>dis[u]+wt){
                dis[v] = dis[u]+wt;
            }
        }
    }
    // nth relaxation to check negative cycle
    for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u]!=1e9 && dis[v]>dis[u]+wt){
                return {-1};
            }
        }    
    return dis;