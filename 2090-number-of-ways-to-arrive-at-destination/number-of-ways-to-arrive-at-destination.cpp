class Solution {
public:
    const int MOD = 1e9 + 7;

    // Modified Dijkstra function
    int dijkstra(vector<vector<pair<int, int>>> &adj, int src, int dest) {
        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX); // Store shortest distances
        vector<int> pathCount(n, 0);         // Store number of shortest paths
        dist[src] = 0;
        pathCount[src] = 1;

        set<pair<long long, int>> st; // {distance, node}
        st.insert({0, src});

        while (!st.empty()) {
            auto [currDist, node] = *st.begin();
            st.erase(st.begin());

            if (node == dest) break; // Stop early if we reach the destination

            for (auto &[nextNode, edgeWeight] : adj[node]) {
                long long newDist = currDist + edgeWeight;

                if (newDist < dist[nextNode]) {
                    // Found a shorter path
                    st.erase({dist[nextNode], nextNode});
                    dist[nextNode] = newDist;
                    pathCount[nextNode] = pathCount[node];
                    st.insert({newDist, nextNode});
                } else if (newDist == dist[nextNode]) {
                    // Found another shortest path
                    pathCount[nextNode] = (pathCount[nextNode] + pathCount[node]) % MOD;
                }
            }
        }

        return (dist[dest] < LLONG_MAX) ? pathCount[dest] : 0;
    }

    // Main function to count paths
    int countPaths(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        // Step 2: Find the shortest path count from 0 to n-1
        return dijkstra(adj, 0, n - 1);
    }
};
