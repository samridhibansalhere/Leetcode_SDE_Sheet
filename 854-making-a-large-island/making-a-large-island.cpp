class DisjointSet {
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1); // Initially, each component has size 1
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] != node) {
            parent[node] = findUltimateParent(parent[node]);
        }
        return parent[node];
    }

    void unionByRank(int u, int v) {
        int rootU = findUltimateParent(u);
        int rootV = findUltimateParent(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
                rank[rootU]++;
            }
        }
    }

    int getSize(int node) {
        return size[findUltimateParent(node)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Step 1: Union adjacent land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        ds.unionByRank(i * n + j, nr * n + nc);
                    }
                }
            }
        }

        // Step 2: Check each zero cell and calculate the size of the island
        int maxIslandSize = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue; // Skip land cells

                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        components.insert(ds.findUltimateParent(nr * n + nc));
                    }
                }

                // Calculate the size of the island if this zero is converted to one
                int size = 1; // Current cell
                for (auto comp : components) {
                    size += ds.getSize(comp);
                }

                maxIslandSize = max(maxIslandSize, size);
            }
        }

        // Step 3: Handle the case where the grid is already full of ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxIslandSize = max(maxIslandSize, ds.getSize(i * n + j));
                }
            }
        }

        return maxIslandSize;
    }
};
