class Solution {
public:
bool check(vector<int>& a,int t)
{
    for(auto i:a)
    {
        if(i==t) return false;
    }
    return true;
}
    vector<int> majorityElement(vector<int>& nums) {
int n=nums.size();
vector<int> a;
unordered_map<int,int> mp;
for(int i=0;i<n;i++)
{
    mp[nums[i]]++;
    if(mp[nums[i]]>(n/3) && check(a,nums[i])) a.push_back(nums[i]);
}        
return a;        
    }
};