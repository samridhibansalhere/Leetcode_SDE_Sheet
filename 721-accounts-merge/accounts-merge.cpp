#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToNode;

        // Map each email to a node using Union-Find
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToNode.find(email) == emailToNode.end()) {
                    emailToNode[email] = i;
                } else {
                    ds.unionByRank(i, emailToNode[email]);
                }
            }
        }

        // Collect emails for each root node
        unordered_map<int, vector<string>> mergedEmails;
        for (auto& [email, node] : emailToNode) {
            int rootNode = ds.findUltimateParent(node);
            mergedEmails[rootNode].push_back(email);
        }

        // Build the result
        vector<vector<string>> result;
        for (auto& [node, emails] : mergedEmails) {
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(accounts[node][0]); // Add account name
            temp.insert(temp.end(), emails.begin(), emails.end());
            result.push_back(temp);
        }

        return result;
    }
};
