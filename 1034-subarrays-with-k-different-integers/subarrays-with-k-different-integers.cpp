#include<bits/stdc++.h>
class Solution {
public:
int func(vector<int>&nums,int k)
{
        unordered_map<int,int> mp;
        int c=0,l=0,r=0;  
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){mp[nums[l]]--; if(mp[nums[l]]==0) mp.erase(nums[l]); l++;}
            if(mp.size()<=k) c+=r-l+1;
            r++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};