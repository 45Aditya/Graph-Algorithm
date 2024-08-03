#include<bits/stdc++.h>
using namespace std;

// way to represent n*m matrix in disjoint cell = row * m + col;

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

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int,int>>> edges;
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                int u = i;
                int v = it[0];
                int w = it[1];
                
                edges.push_back({w, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        int sum = 0;
        for(auto it : edges) {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)) {
                sum += w;
                ds.unionBySize(u, v);
            }
        }
        return sum;
    }
};
