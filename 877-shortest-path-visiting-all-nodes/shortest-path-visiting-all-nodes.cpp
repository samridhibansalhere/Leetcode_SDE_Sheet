#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0; // Single node, no path needed.

        queue<tuple<int, int, int>> q; // (current_node, visited_mask, steps)
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize the queue with all nodes as starting points
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [current, mask, steps] = q.front();
            q.pop();

            // If all nodes are visited, return the steps
            if (mask == (1 << n) - 1) return steps;

            // Explore neighbors
            for (int neighbor : graph[current]) {
                int nextMask = mask | (1 << neighbor);
                if (!visited[neighbor][nextMask]) {
                    q.emplace(neighbor, nextMask, steps + 1);
                    visited[neighbor][nextMask] = true;
                }
            }
        }

        return -1; // Should never reach here
    }
};
