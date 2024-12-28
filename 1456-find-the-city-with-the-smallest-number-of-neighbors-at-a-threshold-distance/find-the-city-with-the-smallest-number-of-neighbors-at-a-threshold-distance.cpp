class Solution {
public:
    int dijkstra(vector<vector<pair<int, int>>> &adj, int src, int distanceThreshold) {
        set<pair<int, int>> st;
        int n = adj.size();
        vector<int> dist(n, 1e9); // Use INT_MAX for clarity
        dist[src] = 0;
        st.insert({0, src});
        
        while (!st.empty()) {
            int weight = (*(st.begin())).first;
            int node = (*(st.begin())).second;
            st.erase(st.begin());
            
            for (auto it : adj[node]) {
                int nextNode = it.first;
                int edgeWeight = it.second;
                
                if (weight + edgeWeight < dist[nextNode]) {
                    if (dist[nextNode] != INT_MAX) {
                        st.erase({dist[nextNode], nextNode});
                    }
                    dist[nextNode] = weight + edgeWeight;
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }
        
        // Count nodes within the distance threshold
        int count = 0;
        for (int d : dist) {
            if (d <= distanceThreshold) count++;
        }
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
        
        vector<int> reachableCities(n);
        for (int i = 0; i < n; ++i) {
            reachableCities[i] = dijkstra(adj, i, distanceThreshold);
        }
        
        // Find the city with the smallest number of reachable cities
        int minReachable = INT_MAX, ans = -1;
        for (int i = n - 1; i >= 0; --i) { // Iterate in reverse to handle ties
            if (reachableCities[i] <minReachable) {
                minReachable = reachableCities[i];
                ans = i;
            }
        }
        return ans;
    }
};
