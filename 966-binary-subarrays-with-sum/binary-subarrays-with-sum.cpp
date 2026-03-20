class Solution {
public:
int func(vector<int>&nums,int k)
{
    if(k<0) return 0;
    int l=0,r=0,c=0,s=0;
    while(r<nums.size())
    {
        s+=nums[r];
        while(s>k){s-=nums[l]; l++;}
        c+=r-l+1;
        r++;
    }
    return c;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums,goal-1);
    }
};