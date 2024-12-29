class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        
        // Min-heap to store {effort, row, col}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if (x == n - 1 && y == m - 1) return effort; // Reached destination

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int newEffort = max(effort, abs(grid[newX][newY] - grid[x][y]));
                    if (newEffort < dist[newX][newY]) {
                        dist[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        return -1; // This line should never be reached
    }
};
