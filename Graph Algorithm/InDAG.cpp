#include<bits/stdc++.h>
using namespace std;

//Shortest Distance in directed acyclic weighted graph with no negative cycle using topo sort

class Solution {
private:
    //Topo Sort using DFS
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& visit, int node, stack<int>& st) {
        visit[node] = 1;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!visit[v]) {
                dfs(adj, visit, v, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Initialize adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        
        // Topological sort
        vector<int> visit(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(!visit[i]) {
                dfs(adj, visit, i, st);
            }
        }
        
        // Initialize distances with a large value
        vector<int> dist(n, 1e9);
        dist[0] = 0; // Assuming the source node is 0
        
        // Relax edges according to topological order
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    if(dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(dist[i]==1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};