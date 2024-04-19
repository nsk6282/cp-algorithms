#include <bits/stdc++.h>
using namespace std;
/*
Articulation points are nodes on whose removal the graph breaks down into multiple components
 we will use two arrays:-
1) tim[]-> dfs time of insertion
2) low[]->lowest time of insertion among all its adjcent nodes except parent and visited nodes
if(low[it]>tin[node]->> it is a bridge )
low[it]>=tin[node];
*/ 
void dfs(int node,int par,vector<int> adj[],vector<int> &vis,int tin[],int low[],int &tim,vector<int> &mark){
    vis[node]=1;
    low[node]=tin[node]=tim;
    tim++;
    int child=0;
    for(auto it:adj[node]){
        if(it==par) continue;
        if(!vis[it]){
            dfs(it,node,adj,vis,tin,low,tim,mark);
            low[node] = min(low[node],low[it]);
            if(low[it]>=tin[node] && par!=-1){
                mark[node]=1;
            }
            child++;
        }
        else low[node] = min(low[node],tin[it]);// change in updation for visited nodes
    }
    if(child>1 && par==-1) mark[node]=1;
    return;
}
vector<int> articulationPoint(int n, vector<int> adj[]){
    int tim=1;
    vector<int> vis(n,0);
    int tin[n];
    int low[n];
    vector<int> mark(n,0);
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,tin,low,tim,mark);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mark[i]) ans.push_back(i);
    }
    return ans;
}

