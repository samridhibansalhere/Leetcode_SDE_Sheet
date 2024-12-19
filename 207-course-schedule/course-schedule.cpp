class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list from edge list
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Detect cycles using Kahn's Algorithm
        vector<int> inDegree(numCourses, 0);
        for (const auto& edges : adj) {
            for (int neighbor : edges) {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) 
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;
            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) 
                    q.push(neighbor);
            }
        }

        // If all nodes are processed, return true (no cycles)
        return count == numCourses;
    }
};
