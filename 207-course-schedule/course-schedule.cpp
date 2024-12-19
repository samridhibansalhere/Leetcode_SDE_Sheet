class Solution {
public:
    void dfs(int node, vector<int>& visited, stack<int>& s, vector<vector<int>>& adj, bool& hasCycle) {
        visited[node] = 1; // Mark node as visiting (gray)
        for (auto neighbor : adj[node]) {
            if (visited[neighbor] == 0) { // Unvisited
                dfs(neighbor, visited, s, adj, hasCycle);
            } else if (visited[neighbor] == 1) { // Back edge (cycle detected)
                hasCycle = true;
                return;
            }
        }
        visited[node] = 2; // Mark node as fully processed (black)
        s.push(node);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list from edge list
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Perform topological sort
        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        stack<int> s;
        bool hasCycle = false;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) { // Unvisited
                dfs(i, visited, s, adj, hasCycle);
                if (hasCycle) return false; // Cycle detected
            }
        }

        // If we processed all nodes, the graph is a DAG
        return true;
    }
};
