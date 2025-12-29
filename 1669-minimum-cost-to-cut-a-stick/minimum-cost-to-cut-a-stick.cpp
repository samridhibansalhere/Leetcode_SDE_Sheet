class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        n=cuts.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i;j<n-1;j++)
            {
                int steps=1e9;
                for(int k=i;k<=j;k++) steps=min(steps,cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                dp[i][j]=steps;
            }
        }
        return dp[1][n-2];
    }
};