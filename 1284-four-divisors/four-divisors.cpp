#include<bits/stdc++.h>
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=0;
            int s=0;
            int b=sqrt(nums[i]);
            for(int j=2;j<=b;j++)
            {
                if(j*j==nums[i]) c++;
                if(nums[i]%j==0){c++; s+=j;}
            }
            if(c==1 && b*b!=nums[i]) ans+=1+nums[i]+s+(nums[i]/s);
        }
        return ans;
    }
};