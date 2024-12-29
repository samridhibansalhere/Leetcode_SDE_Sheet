class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1; // Start or end cell is blocked
        }

        // Direction vectors for 8 possible moves
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},          {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        dist[0][0] = 1; // Start at the first cell with distance 1
        q.push({1, {0, 0}});
        
        while (!q.empty()) {
            auto [d, pos] = q.front();
            auto [a, b] = pos;
            q.pop();

            for (auto dir : directions) {
                int newA = a + dir.first;
                int newB = b + dir.second;

                if (newA >= 0 && newA < n && newB >= 0 && newB < n && grid[newA][newB] == 0) {
                    if (d + 1 < dist[newA][newB]) {
                        dist[newA][newB] = d + 1;
                        q.push({d + 1, {newA, newB}});
                    }
                }
            }
        }

        return (dist[n-1][n-1] < 1e9) ? dist[n-1][n-1] : -1;
    }
};
