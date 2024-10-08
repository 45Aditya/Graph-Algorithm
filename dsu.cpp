#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);  // Initialize size to 1 for each node
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        } 
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int Up_u = findParent(u);
        int Up_v = findParent(v);
        if(Up_u == Up_v) return;
        if(rank[Up_u] < rank[Up_v]) {
            parent[Up_u] = Up_v;
        } else if(rank[Up_v] < rank[Up_u]) {
            parent[Up_v] = Up_u;
        } else {
            parent[Up_v] = Up_u;
            rank[Up_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int Up_u = findParent(u);
        int Up_v = findParent(v);
        if(Up_u == Up_v) return;
        if(size[Up_u] < size[Up_v]) {
            parent[Up_u] = Up_v;
            size[Up_v] += size[Up_u];  // Update size correctly
        } else {
            parent[Up_v] = Up_u;
            size[Up_u] += size[Up_v];  // Update size correctly
        }
    }
};