class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int> ans1(nums.size(),nums[nums.size()-1]);
        vector<int> ans2(nums.size(),nums[0]);
        for(int i=nums.size()-2;i>=0;i--)
        {
           ans1[i]=max(ans1[i+1],nums[i]);
        }
        for(int i=1;i<nums.size();i++)
        {
            ans2[i]=max(ans2[i-1],nums[i]);
        }
        int c=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            c+=min(ans1[i],ans2[i])-nums[i];
        }
        return c;   
    }
};