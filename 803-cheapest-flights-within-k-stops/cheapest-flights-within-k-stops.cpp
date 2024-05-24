class Solution {
public:
    vector<int> check(vector<vector<int>>& flights, int s) {
        vector<int> a;
        for (int i = 0; i < flights.size(); ++i) {
            if (flights[i][0] == s) {
                a.push_back(flights[i][1]);
            }
        }
        return a;
    }

    int calc(vector<vector<int>>& flights, int s, int e) {
        for (int i = 0; i < flights.size(); ++i) {
            if (flights[i][0] == s && flights[i][1] == e) {
                return i;
            }
        }
        return -1;
    }

    int solve(int src, int dst, int k, vector<vector<int>>& flights, vector<vector<int>>& dp) {
        if (src == dst) return 0; 
        if (k < 0) return INT_MAX;
        if (dp[src][k] != -1) return dp[src][k];
        vector<int> destinations = check(flights, src);
        int minCost = INT_MAX;

        for (int i : destinations) {
            int index = calc(flights, src, i);
            if (index != -1) {
                int cost1 = flights[index][2];
                int cost2 = solve(i, dst, k - 1, flights, dp);
                if (cost2 != INT_MAX) {
                    minCost = min(minCost, cost1 + cost2);
                }
            }
        }
        return dp[src][k] = minCost;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
        int result = solve(src, dst, k, flights, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};
