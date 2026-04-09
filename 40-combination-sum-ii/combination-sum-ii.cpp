class Solution {
public:
void helper(int index,vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target)
{
    if(target==0){ ans.push_back(v); return;}
    if(index==candidates.size() || target<0) return;
    for(int i=index;i<candidates.size();i++)
    {
        if(i>index && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target) break;
        v.push_back(candidates[i]);
        helper(i+1,v,ans,candidates,target-candidates[i]);
        v.pop_back();
    } 
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,v,ans,candidates,target);
        return ans;
    }
};