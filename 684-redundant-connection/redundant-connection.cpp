#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1); // Parent array (1-indexed)
        
        // Initialize each node's parent as itself
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        
        // Find function with path compression (use std::function for recursion)
        function<int(int)> find = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]); // Path compression
            }
            return parent[node];
        };
        
        // Union function to merge two sets
        auto unionSets = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) {
                return false; // Cycle detected
            }
            parent[rootU] = rootV; // Union
            return true;
        };
        
        // Process each edge
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!unionSets(u, v)) {
                return edge; // This edge forms a cycle
            }
        }
        
        return {}; // Shouldn't reach here
    }
};
