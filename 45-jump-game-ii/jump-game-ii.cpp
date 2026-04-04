class Solution {
public:
int helper(int index,vector<int>&nums,vector<int>&dp)
{
    if(index>=nums.size()-1) return 0;
    if(dp[index]!=-1) return dp[index];
    int mini=1e9;
    for(int i=1;i<=nums[index];i++)
    {
        if(index+i<nums.size()) mini=min(mini,1+helper(index+i,nums,dp));
    }
    return dp[index]=mini;
}
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};