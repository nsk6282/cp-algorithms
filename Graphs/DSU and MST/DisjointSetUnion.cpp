#include <bits/stdc++.h>
using namespace std;
// used for dynamic graphs - online queries
// 2 important functions - findPar() and Union()[bysize,byrank]
// tc-> O(4*alpha) = O(constant time);
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