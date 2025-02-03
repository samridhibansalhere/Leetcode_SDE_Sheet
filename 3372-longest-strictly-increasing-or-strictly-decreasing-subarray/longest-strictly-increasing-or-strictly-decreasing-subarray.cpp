class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int n=nums.size();
        int curr1=1,curr2=1,ans=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                curr1++;
                curr2=1;
            }
            else if(nums[i]<nums[i-1])
            {
                curr2++;
                curr1=1;
            }
            else {
                curr1=1;
                curr2=1;
            }
            ans=max(ans,max(curr1,curr2));
        }
        return ans;  
    }
};