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
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(0,-1,n,nums,dp);
    }
};