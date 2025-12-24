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
        vector<int> prev(2,0);
        vector<int> curr(2,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                long long profit=0;
                if(buy) profit=max(-prices[index]+curr[0],curr[1]);
                else profit=max(prices[index]+curr[1],curr[0]);
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};