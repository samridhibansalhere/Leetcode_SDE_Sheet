class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (const auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> discovery(n, -1), low(n, -1); // Discovery and low times
        vector<vector<int>> bridges;
        int time = 0;

        function<void(int, int)> dfs = [&](int node, int parent) {
            discovery[node] = low[node] = time++;
            for (int neighbor : adj[node]) {
                if (neighbor == parent) continue; // Ignore the edge to the parent
                if (discovery[neighbor] == -1) { // If the neighbor is unvisited
                    dfs(neighbor, node);
                    low[node] = min(low[node], low[neighbor]);
                    if (low[neighbor] > discovery[node]) { // Bridge condition
                        bridges.push_back({node, neighbor});
                    }
                } else { // Back edge
                    low[node] = min(low[node], discovery[neighbor]);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            if (discovery[i] == -1) {
                dfs(i, -1);
            }
        }

        return bridges;
    }
};
