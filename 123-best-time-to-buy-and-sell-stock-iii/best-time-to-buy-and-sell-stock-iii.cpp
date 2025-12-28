class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        long long profit=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy) profit=max(-prices[index]+dp[index+1][0][cap],dp[index+1][1][cap]);
                    else profit=max(prices[index]+dp[index+1][1][cap-1],dp[index+1][0][cap]);
                    dp[index][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
        }
};