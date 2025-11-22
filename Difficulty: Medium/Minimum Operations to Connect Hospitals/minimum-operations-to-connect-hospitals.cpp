#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;
    DSU(int n): parent(n), rankv(n,0) {
        for(int i=0;i<n;++i) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        int redundant = 0;
        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(!dsu.unite(u,v)) ++redundant;
        }
        // count connected components
        unordered_set<int> roots;
        for(int i=0;i<V;++i) roots.insert(dsu.find(i));
        int components = (int)roots.size();
        int need = components - 1;
        return (redundant >= need) ? need : -1;
    }
};