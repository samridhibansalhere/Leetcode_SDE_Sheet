class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> parent(n,0);
        int index=0;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            parent[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;   
                }
            }
            if(dp[i]>ans)
            {
                ans=dp[i];
                index=i;
            }
        }
        vector<int> lis;
        while(index!=parent[index])
        {
            lis.push_back(nums[index]);
            index=parent[index];
        }
        lis.push_back(nums[index]);
        return lis;
    }
};