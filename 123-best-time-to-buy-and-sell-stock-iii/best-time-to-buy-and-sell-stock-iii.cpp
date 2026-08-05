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
        vector<vector<int>> dp(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        int cap=2;
        for(int i=n-1;i>=0;i--)
        {
            for(int flag=0;flag<=1;flag++)
            {
                for(int c=1;c<=cap;c++)
                {
                    if(flag) {curr[flag][c]=max(-prices[i]+dp[0][c],dp[1][c]);}
                    else  curr[flag][c]=max(prices[i]+dp[1][c-1],dp[0][c]);
                }
            }
            dp=curr;
        }
        return dp[1][2];
    }
};