class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0); // To track if a node has been visited
        int maxLength = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> dfsPath; // Track the nodes in the current DFS and their step index
                int current = i, step = 0;

                while (current != -1 && !visited[current]) {
                    visited[current] = 1;
                    dfsPath[current] = step++; // Mark the node and store the step at which it was visited
                    current = edges[current];
                }

                if (current != -1 && dfsPath.count(current)) {
                    // Cycle detected: calculate its length
                    maxLength = max(maxLength, step - dfsPath[current]);
                }
            }
        }

        return maxLength;
    }
};
