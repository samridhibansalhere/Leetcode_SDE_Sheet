class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int k=0;
        int n=prices.size();
       vector<vector<long long>> dp(n+k+1,vector<long long>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int flag=0;flag<=1;flag++)
            {
                if(flag) dp[i][flag]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][flag]=max(prices[i]-fee+dp[i+1+k][1],dp[i+1][0]);
            }
        }
        return dp[0][1]; 
    }
};