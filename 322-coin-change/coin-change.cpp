class Solution {
public:
int helper(int index,int amount,vector<int>& coins,vector<vector<int>>& dp)
{
    if(amount==0) return 0;
    if(index==0) return (amount%coins[0]==0)?amount/coins[0]:1e9;
    if(dp[index][amount]!=-1) return dp[index][amount];
    int nottake=helper(index-1,amount,coins,dp);
    int take=1e9;
    if(amount>=coins[index]) take=1+helper(index,amount-coins[index],coins,dp);
    return dp[index][amount]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
       vector<vector<int>> dp(n,vector<int>(amount+1,-1));
       sort(coins.begin(),coins.end());
    return (helper(n-1,amount,coins,dp)<1e9)?helper(n-1,amount,coins,dp):-1;
    }
};