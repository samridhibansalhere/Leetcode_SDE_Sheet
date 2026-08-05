class Solution {
public:
int f(int i,int flag,int n,vector<int>& prices,vector<vector<int>>& dp){
if(i==n) return 0;
if(dp[i][flag]!=-1) return dp[i][flag];
if(flag) return dp[i][flag]=max(-prices[i]+f(i+1,0,n,prices,dp),f(i+1,1,n,prices,dp));
else return dp[i][flag]=max(prices[i]+f(i+1,1,n,prices,dp),f(i+1,0,n,prices,dp));
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int flag=0;flag<=1;flag++)
            {
                if(flag) curr[flag]=max(-prices[i]+dp[0],dp[1]);
                else curr[flag]=max(prices[i]+dp[1],dp[0]);
            }
            dp=curr;
        }
        return dp[1];
    }
};