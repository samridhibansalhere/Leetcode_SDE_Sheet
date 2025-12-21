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
       vector<int> prev(amount+1,1e9),curr(amount+1,1e9);
       sort(coins.begin(),coins.end());
       if(amount==0) return 0;
       for(int i=0;i<=amount;i++)
       if(i%coins[0]==0) prev[i]=curr[i]=i/coins[0];
       for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++){
                int nottake=prev[j];
                int take=1e9;
                if(j>=coins[i]) take=1+curr[j-coins[i]];
                curr[j]=min(nottake,take);
                }
            prev=curr;
       }
       return (prev[amount]<1e9)? prev[amount]:-1;
    }
};