#include<bits/stdc++.h>
using namespace std;

//Using Priority Queue
class Solution
{
	public:
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        vector<int> dist(v,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]) {
                int v = it[0];
                int w = it[1];
                if(dis + w < dist[v]) {
                    dist[v] = dis + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

//Using Set

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        st.insert({0,S});
        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]) {
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(edgeWeight + dis < dist[adjNode]) {
                    if(dist[adjNode]!=1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = edgeWeight + dis;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};