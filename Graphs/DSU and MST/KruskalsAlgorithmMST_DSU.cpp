#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
private:
    vector<int> par,rank,size;
public:
    DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0 );
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }
    int findPar(int n){
        if(par[n]==n) return n;
        else return par[n] = findPar(par[n]);//path compression
    }
    //tc-> O(logn);
    void unionByRank(int u,int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            par[pv] = pu;
        }
        else if(rank[pv]>rank[pu]) par[pu] = pv;
        else{
            par[pv] = pu;
            rank[pu]++;
        }
        return;
    }
    void unionBySize(int u,int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu==pv) return;
        if(size[pu]>size[pv]){
            par[pv] =pu;
            size[pu]+=size[pv];
        }
        else{
            par[pu] =pv;
            size[pv]+=size[pu];
        }
    }
};
bool comp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
//sort the edges by weight and disjoint on 
int minimumSpanningTree(vector<vector<int>>& edges, int n){
    int sum=0;
    vector<pair<int,int>> MST;
    sort(edges.begin(),edges.end(),comp);//sort by edge weights
    DisjointSet ds(n);
    for(auto it:edges){
        int u=it[0],v = it[1],w = it[2];
        if(ds.findPar(u)==ds.findPar(v)) continue;
        ds.unionBySize(u,v);
        MST.push_back({u,v});
        sum+=w;
    }
    return sum;
}