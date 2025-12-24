class Solution {
public:
 long long helper(int index,int buy,int n,vector<int>& prices,vector<vector<int>> &dp){
    if(index==n) return 0;
     long long profit=0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy) profit=max(-prices[index]+helper(index+1,0,n,prices,dp),helper(index+1,1,n,prices,dp));
    else profit=max(prices[index]+helper(index+1,1,n,prices,dp),helper(index+1,0,n,prices,dp));
    return dp[index][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return (int)helper(0,1,n,prices,dp);
    }
};