class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int result = 0;

        // Build the adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // DFS with modulo operation
        function<int(int)> dfs = [&](int node) {
            visited[node] = true;
            long long remainder = values[node] % k; // Take modulo during traversal
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    remainder += dfs(neighbor);
                    remainder %= k; // Keep remainder under control
                }
            }
            // Check divisibility
            if (remainder == 0) {
                result++; // This component is divisible by k
                return 0; // Reset remainder for this component
            }
            return static_cast<int>(remainder); // Return remainder
        };

        // Traverse all nodes
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return result;
    }
};
