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
    int removeStones(vector<vector<int>>& stones) {
        int mr=0,mc=0;
        for(auto it:stones){
            mr=max(mr,it[0]);
            mc=max(mc,it[1]);
        }
        DisjointSet ds(mr+mc+2);
        unordered_map<int,int> mp; 
        for(auto it:stones){
            int r=it[0];
            int c=it[1]+mr+1;
            ds.unionByRank(r,c);
            mp[r]=1;
            mp[c]=1;
        }
        int count=0;
        for(auto it:mp){
            if(ds.findUltimateParent(it.first)==it.first) count++;
        }
        return stones.size()-count;
    }
};