class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n,1e9);
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto [stops, state] = q.front();
            auto [node, currentCost] = state;
            q.pop();
           
            if (stops > k) continue;
            for (auto& [neighbor, price] : graph[node]) {
                int newCost = currentCost + price;
                if (newCost < dist[neighbor] && stops<=k) {
                    dist[neighbor] = newCost;
                    q.push({stops+1, {neighbor, newCost}});
                }
            }
        }
        return (dist[dst]==1e9)?-1:dist[dst];
    }
};
