#include <bits/stdc++.h>
using namespace std;
// MULTISOURCE SHORTEST PATH
// for undirected graphs make sure you count edge bothways(2times u->v and v->u)
// also helps to detect negative cycles
//go via all nodes
// if distance of any node from itself is less than zero, there is an negative cycle;
//time c O(n3)
vector<vector<int>> FloydWarshall(int n,vector<vector<int>> &edges) {
    vector<vector<int>> disMatrix(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++) disMatrix[i][i]=0;
    for(auto it:edges){
        disMatrix[it[0]][it[1]] = it[2];
        disMatrix[it[1]][it[0]] = it[2];
    }
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int d1 = disMatrix[i][via], d2 = disMatrix[via][j];
                if(d1==1e9 || d2 == 1e9) continue;
                disMatrix[i][j] = min(disMatrix[i][j],d1+d2);
            }
            
        }
    }
    return disMatrix;
}