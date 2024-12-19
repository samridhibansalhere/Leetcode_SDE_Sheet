class Solution {
public:
    void dfs(int node, vector<int>& visited, stack<int>& s, vector<vector<int>>& adj, bool& hasCycle) {
        visited[node] = 1; 
        for (auto neighbor : adj[node]) {
            if (visited[neighbor] == 0) { 
                dfs(neighbor, visited, s, adj, hasCycle);
            } else if (visited[neighbor] == 1) { 
                hasCycle = true;
                return;
            }
        }
        visited[node] = 2; 
        s.push(node);
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        
        // Build adjacency list
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Kahn's Algorithm to detect cycle and get topological order
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<vector<int>> colorCount(n, vector<int>(26, 0)); // To store counts of each color
        int nodesProcessed = 0;
        int maxColorValue = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesProcessed++;

            // Update the color count for this node
            colorCount[node][colors[node] - 'a']++;

            // Update max color value
            maxColorValue = max(maxColorValue, colorCount[node][colors[node] - 'a']);

            for (auto neighbor : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    colorCount[neighbor][c] = max(colorCount[neighbor][c], colorCount[node][c]);
                }

                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        // If we processed fewer nodes than exist in the graph, there is a cycle
        if (nodesProcessed < n) return -1;

        return maxColorValue;
    }
};
