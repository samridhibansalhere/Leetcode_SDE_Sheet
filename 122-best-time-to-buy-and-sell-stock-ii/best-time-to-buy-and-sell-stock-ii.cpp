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
        int dp0=0,dp1=0,curr0=0,curr1=0;
        for(int i=n-1;i>=0;i--)
        {
            curr0=max(prices[i]+dp1,dp0);
            curr1=max(-prices[i]+dp0,dp1);
            dp0=curr0;
            dp1=curr1;
        }
        return dp1;
    }
};