class Solution {
public:
bool palindrome(string s,int start,int end){
    while(start<=end)
    {
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}
void helper(int index,string s,vector<string>&v,vector<vector<string>>&ans){
    if(index==s.size()) {ans.push_back(v); return;}
    for(int i=index;i<s.size();i++)
    {
        if(palindrome(s,index,i))
        {
            v.push_back(s.substr(index,i-index+1));
            helper(i+1,s,v,ans);
            v.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
      vector<string> v;
      vector<vector<string>> ans;
      helper(0,s,v,ans);
      return ans;
    }
};