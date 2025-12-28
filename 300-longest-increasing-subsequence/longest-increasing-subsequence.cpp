class Solution {
public:
int helper(int index,int pindex,int n,vector<int>& nums,vector<vector<int>>& dp){
    if(index==n) return 0;
    if(dp[index][pindex+1]!=-1) return dp[index][pindex+1];
    int length=helper(index+1,pindex,n,nums,dp);
    if(pindex ==-1 || nums[index]>nums[pindex]) length=max(length,1+helper(index+1,index,n,nums,dp));
    return dp[index][pindex+1]=length;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        for(int i=0;i<=n;i++) dp[n][i]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int pindex=index-1;pindex>=-1;pindex--){
                dp[index][pindex+1] = dp[index+1][pindex+1];
                if(pindex ==-1 || nums[index]>nums[pindex]) dp[index][pindex+1]=max(dp[index][pindex+1],1+dp[index+1][index+1]);
            }
        }    
        return dp[0][0];
    }
};