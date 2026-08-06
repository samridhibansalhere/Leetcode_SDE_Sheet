#include<bits/stdc++.h>
class Solution {
public:
bool compare(string &a,string &b){
    int i=0,j=0;
    while(i<a.size()){
        if(j<b.size() &&a[i]==b[j] ){i++; j++;}
        else i++;
    }
    return j==b.size();
}
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
         sort(nums.begin(), nums.end(),
         [](string &a, string &b) {
         return a.size() < b.size();
         });
        vector<int> hash(n,0);
        int maxi=1;
        int c=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int p=0;p<i;p++)
            {
                if(nums[i].size()==nums[p].size()+1 && compare(nums[i],nums[p]) && 1+dp[p]>dp[i]){ dp[i]=1+dp[p]; hash[i]=p; }
            }
            if(dp[i]>maxi) {maxi=dp[i]; c=i;}
        }
        vector<string> s;
        while(hash[c]!=c)
        {
            s.push_back(nums[c]);
            c=hash[c];
        }
        s.push_back(nums[c]);
        reverse(s.begin(), s.end());
        
        return maxi;
    }
};