#include <queue>
#include <vector>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::queue<std::pair<int, int>> q;
        int freshOranges = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto& dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshOranges--;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }

        return freshOranges == 0 ? time : -1;
    }
};
