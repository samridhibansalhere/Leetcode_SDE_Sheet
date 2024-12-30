class DisjointSet {
private:
    vector<int> parent, rank;

public:
    // Constructor to initialize the parent and rank arrays
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find with path compression
    int findUltimateParent(int node) {
        if (parent[node] != node) {
            parent[node] = findUltimateParent(parent[node]); // Path compression
        }
        return parent[node];
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int rootU = findUltimateParent(u);
        int rootV = findUltimateParent(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        // Process the isConnected matrix to union connected nodes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }

        // Count unique provinces by counting unique roots
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (ds.findUltimateParent(i) == i) { // Node is a root
                provinces++;
            }
        }

        return provinces;
    }
};
