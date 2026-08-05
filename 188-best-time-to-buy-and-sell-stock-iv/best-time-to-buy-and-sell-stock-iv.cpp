class Solution {
public:
int f(int i,int t,int n,int k,vector<int>& prices,vector<vector<int>>& dp){
if(i==n || t==2*k) return 0;
if(dp[i][t]!=-1) return dp[i][t];
if(t%2==0) return dp[i][t]=max(-prices[i]+f(i+1,t+1,n,k,prices,dp),f(i+1,t,n,k,prices,dp));
else return dp[i][t]=max(prices[i]+f(i+1,t+1,n,k,prices,dp),f(i+1,t,n,k,prices,dp));
}
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        vector<int> curr(2*k+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int t=2*k-1;t>=0;t--)
            {
                if(t%2==0) dp[i][t]=max(-prices[i]+dp[i+1][t+1],dp[i+1][t]);
                else dp[i][t]=max(prices[i]+dp[i+1][t+1],dp[i+1][t]);
            }
        }
        return dp[0][0];
    }
};