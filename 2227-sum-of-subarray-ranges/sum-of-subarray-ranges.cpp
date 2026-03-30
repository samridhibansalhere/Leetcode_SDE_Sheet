class Solution {
public:
    long long sumSubarrayMins(vector<int>& nums) {
        vector<int> ans1(nums.size()),ans2(nums.size());
        stack<int> st1,st2;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st1.empty() && nums[st1.top()]>=nums[i]) st1.pop();
            ans1[i]=(!st1.empty())?st1.top()-i:nums.size()-i;
            st1.push(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            while(!st2.empty() && nums[st2.top()]>nums[i]) st2.pop();
            ans2[i]=(!st2.empty())?i-st2.top():i+1;
            st2.push(i);
        }
        long long t=0;
        for(int i=0;i<nums.size();i++)
        {
            t=t+ans1[i]*ans2[i]*1LL*nums[i];
        }
        return t;   
    }
    long long sumSubarrayMaxs(vector<int>& nums) {
        vector<int> ans1(nums.size()),ans2(nums.size());
        stack<int> st1,st2;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st1.empty() && nums[st1.top()]<=nums[i]) st1.pop();
            ans1[i]=(!st1.empty())?st1.top()-i:nums.size()-i;
            st1.push(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            while(!st2.empty() && nums[st2.top()]<nums[i]) st2.pop();
            ans2[i]=(!st2.empty())?i-st2.top():i+1;
            st2.push(i);
        }
        long long t=0;
        for(int i=0;i<nums.size();i++)
        {
            t=t+ans1[i]*ans2[i]*1LL*nums[i];
        }
        return t;   
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};