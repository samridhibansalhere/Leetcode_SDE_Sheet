class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;
        pq.push({0, {src, 0}});
        while (!pq.empty()) {
            auto [currentCost, state] = pq.top();
            auto [node, stops] = state;
            pq.pop();
            if (node == dst) return currentCost;
            if (stops > k) continue;
            for (auto& [neighbor, price] : graph[node]) {
                int newCost = currentCost + price;
                if (newCost < dist[neighbor][stops + 1]) {
                    dist[neighbor][stops + 1] = newCost;
                    pq.push({newCost, {neighbor, stops + 1}});
                }
            }
        }
        return -1;
    }
};
