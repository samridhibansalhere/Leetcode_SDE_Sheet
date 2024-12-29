class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n); // adjacency list
        
        // Build adjacency list with Manhattan distances
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        // Minimum Spanning Tree using Prim's Algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> visited(n, 0);
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            if (visited[node] == 1) continue;
            visited[node] = 1;
            sum += weight;

            for (auto& [adjNode, wt] : adj[node]) {
                if (!visited[adjNode]) {
                    pq.push({wt, adjNode});
                }
            }
        }
        
        return sum;
    }
};
