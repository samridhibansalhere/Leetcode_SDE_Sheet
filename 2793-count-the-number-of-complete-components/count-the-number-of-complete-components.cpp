#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<int> componentSize(n, 0);
        vector<int> edgeCount(n, 0);

        // Process edges to build connected components
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ds.unionByRank(u, v);
        }

        // Count nodes and edges in each component
        for (int i = 0; i < n; i++) {
            int root = ds.findUltimateParent(i);
            componentSize[root]++;
        }

        for (auto& edge : edges) {
            int uRoot = ds.findUltimateParent(edge[0]);
            edgeCount[uRoot]++;
        }

        // Count complete components
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            if (componentSize[i] > 0) {
                int expectedEdges = (componentSize[i] * (componentSize[i] - 1)) / 2;
                if (edgeCount[i] == expectedEdges) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
