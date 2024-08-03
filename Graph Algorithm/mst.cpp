#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        int sum = 0;
        vector<vector<pair<int, int>>> grid(n);
    
        // Parse the adjacency list into a grid representation
        for (int i = 0; i < n; i++) {
            for (auto edge : adj[i]) {
                int u = i;
                int v = edge[0];
                int w = edge[1];
                grid[u].push_back({v, w});
                grid[v].push_back({u, w});
            }
        }
    
        // Vector to keep track of visited nodes
        vector<int> visit(n, 0);
        // Priority queue to select the edge with the smallest weight
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
        // Start with the 0th node
        pq.push({0, {0, -1}});
    
        while (!pq.empty()) {
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            int weight = pq.top().first;
            pq.pop();
    
            // If the node is already visited, skip it
            if (visit[node]) continue;
    
            // Mark the node as visited
            visit[node] = 1;
            
            // Add the weight to the sum
            if (parent != -1) {
                sum += weight;
            }
    
            // Add all the adjacent edges of the current node to the priority queue
            for (auto it : grid[node]) {
                if (!visit[it.first]) {
                    pq.push({it.second, {it.first, node}});
                }
            }
        }
        return sum;
    }

};