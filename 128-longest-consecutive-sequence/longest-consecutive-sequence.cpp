class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
int n=nums.size();
if(n==0) return 0;
sort(nums.begin(),nums.end());
int len=0;
int ans=0;
int c=0;
vector<int> a;
a.push_back(nums[0]);
for(int i=1;i<n;i++)
{
    if(nums[i]!=nums[i-1]) a.push_back(nums[i]);
}
n=a.size();
nums=a;
for(int i=1;i<n;i++)
{
    if(nums[i]==nums[i-1]+1) c++;
    else c=0;
    len=max(c,len);
    ans=max(len,ans);
} 
return ans+1;       
    }
};
