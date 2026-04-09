class Solution {
public:void helper(int index,vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target)
{
    if(target==0){ ans.push_back(v); return;}
    if(index==candidates.size()) return;
    if(candidates[index]<=target){
        v.push_back(candidates[index]);
        helper(index,v,ans,candidates,target-candidates[index]);
        v.pop_back();
    } 
    helper(index+1,v,ans,candidates,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,v,ans,candidates,target);
        return ans;
    }
};