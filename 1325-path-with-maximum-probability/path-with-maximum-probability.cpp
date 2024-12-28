class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build adjacency list with probabilities as weights
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // Priority queue to store {probability, node}, max-heap by probability
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node}); // Start with probability 1 at start_node

        vector<double> maxProb(n, 0.0); // Maximum probability to each node
        maxProb[start_node] = 1.0;

        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            // Early exit if we've reached the destination
            if (node == end_node) return currProb;

            // Explore neighbors
            for (auto &[nextNode, edgeProb] : adj[node]) {
                double newProb = currProb * edgeProb;
                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        // If we never reach the end_node, return 0
        return 0;
    }
};
