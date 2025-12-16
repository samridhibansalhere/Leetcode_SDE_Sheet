class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n-1] = matrix[n-1];
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = dp[i+1][j];
                int left = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int right = (j < n-1) ? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = min({down, left, right}) + matrix[i][j];
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
