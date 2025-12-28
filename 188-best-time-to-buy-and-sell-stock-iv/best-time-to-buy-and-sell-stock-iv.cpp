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
    int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        long long profit=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(buy) profit=max(-prices[index]+ahead[0][cap],ahead[1][cap]);
                    else profit=max(prices[index]+ahead[1][cap-1],ahead[0][cap]);
                    curr[buy][cap]=profit;
                }
            }
            ahead=curr;
        }
        return ahead[1][k];
        }
};