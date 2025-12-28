class Solution {
public:
 long long helper(int index,int buy,int cap,int n,vector<int>& prices,vector<vector<vector<int>>> &dp){
    if(index==n || cap==0) return 0;
    long long profit=0;
    if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
    if(buy) profit=max(-prices[index]+helper(index+1,0,cap,n,prices,dp),helper(index+1,1,cap,n,prices,dp));
    else profit=max(prices[index]+helper(index+1,1,cap-1,n,prices,dp),helper(index+1,0,cap,n,prices,dp));
    return dp[index][buy][cap]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,2,n,prices,dp);
    }
};