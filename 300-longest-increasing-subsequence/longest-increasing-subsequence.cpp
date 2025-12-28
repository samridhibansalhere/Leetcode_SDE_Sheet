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
        vector<int> curr(n+1,0);
        vector<int> ahead(n+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int pindex=index;pindex>=0;pindex--){
                curr[pindex] = ahead[pindex];
                if(pindex ==0 || nums[index]>nums[pindex-1]) curr[pindex]=max(curr[pindex],1+ahead[index+1]);
            }
            ahead=curr;
        }    
        return ahead[0];
    }
};
