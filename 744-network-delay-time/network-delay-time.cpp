class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight}); // Directed edge
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n + 1, LLONG_MAX);
        dist[k] = 0;
        pq.push({0, k}); // Initialize the source

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;

                if (dis + weight < dist[adjNode]) {
                    dist[adjNode] = dis + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        long long maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == LLONG_MAX) return -1; // Node not reachable
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
