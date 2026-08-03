class Solution {
public:
int f(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(amount%coins[0]==0) return amount/coins[0];
        else return 1e9;
    }
    if(dp[index][amount]!=-1) return dp[index][amount];
    int nontake=f(index-1,amount,coins,dp);
    int take=INT_MAX;
    if(amount>=coins[index]) take=1+f(index,amount-coins[index],coins,dp);
    return dp[index][amount]=min(nontake,take); 
}
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount+1,0);
      
      for(int w=0;w<=amount;w++)
      {
        if(w%coins[0]==0) dp[w]=w/coins[0];
        else dp[w]=1e9;
      }
      for(int index=1;index<coins.size();index++)
      {
        vector<int> curr(amount+1,0);
        for(int w=0;w<=amount;w++)
        {
            int nontake=dp[w];
            int take=INT_MAX;
            if(w>=coins[index]) take=1+curr[w-coins[index]];
            curr[w]=min(nontake,take); 
        }
        dp=curr;
      }
      int val=dp[amount];
      if(val<1e9) return val;
      else return -1;
    }
};