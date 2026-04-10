class Solution {
public:
void helper(int index,vector<int>&nums,vector<bool>&check,vector<int>&v,vector<vector<int>>&ans)
{
    if(v.size()==nums.size()){ans.push_back(v); return;}
    for(int i=0;i<nums.size();i++)
    {
        if(check[i]) continue;
        check[i]=true;
        v.push_back(nums[i]);
        helper(i+1,nums,check,v,ans);
        v.pop_back();
        check[i]=false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> check(nums.size(),false); 
        helper(0,nums,check,v,ans);
        return ans;  
    }
};