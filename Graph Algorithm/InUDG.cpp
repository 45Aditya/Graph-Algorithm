#include<bits/stdc++.h>
using namespace std;

//Shortest Path in Undirected Graph with unit weight using BFS
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
        // Initialize adjacency list
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            // Add edge to the adjacency list for both directions (undirected graph)
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize distances with a large value (1e9)
        vector<int> dist(n, 1e9);
        // Queue for BFS
        queue<int> q;
        // Start from the source node
        q.push(src);
        dist[src] = 0;

        // BFS to find shortest path
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            // Explore all adjacent nodes
            for(auto it : adj[node]) {
                int v = it;
                // If a shorter path is found
                if(dist[node] + 1 < dist[v]) {
                    dist[v] = dist[node] + 1;
                    q.push(v); // Push the adjacent node into the queue
                }
            }
        }

        // Set distance to -1 for nodes that are not reachable
        for(int i = 0; i < n; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist; // Return the distance array
    }
};
