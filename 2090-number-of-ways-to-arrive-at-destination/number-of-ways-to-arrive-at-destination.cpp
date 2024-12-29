class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX); // Use long long for distances
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

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
                    ways[adjNode] = ways[node];
                } else if (dis + weight == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
