#include<bits/stdc++.h>
class Solution {
public:
bool compare(string &a,string &b){
    if(a.size()-b.size()!=1) return false;
    int i=0,j=0;
    while(i<a.size()){
        if(a[i]==b[j] && j<b.size()){i++; j++;}
        else i++;
    }
    return j==b.size();
}
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end(),
         [](string &a, string &b) {
         return a.size() < b.size();
         });
        vector<int> dp(n,1);
        vector<int> parent(n,0);
        int index=0;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            parent[i]=i;
            for(int j=0;j<i;j++)
            {
                if(compare(nums[i],nums[j]) && dp[j]+1>dp[i]){
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
        vector<string> lis;
        while(index!=parent[index])
        {
            lis.push_back(nums[index]);
            index=parent[index];
        }
        lis.push_back(nums[index]);
        reverse(lis.begin(),lis.end());
        return ans;
    }
};