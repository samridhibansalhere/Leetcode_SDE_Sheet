class Solution {
public:
int f(int i,int p,int n,vector<int>&arr,vector<vector<int>>& dp){
    if(i==n) return 0;
    if(dp[i][p]!=-1) return dp[i][p];
    int nontake=0+f(i+1,p,n,arr,dp);
    int take=INT_MIN;
    if(p==0 || arr[i]>arr[p-1]) take=1+f(i+1,i+1,n,arr,dp);
    return dp[i][p]=max(nontake,take);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int i=n-1;i>=0;i--)
       {
        for(int p=i-1;p>=-1;p--)
        {
            int nontake=0+dp[i+1][p+1];
            int take=INT_MIN;
            if(p==-1 || nums[i]>nums[p]) take=1+dp[i+1][i+1];
            dp[i][p+1]=max(nontake,take);
        }
       }
       return dp[0][0];
    }
};