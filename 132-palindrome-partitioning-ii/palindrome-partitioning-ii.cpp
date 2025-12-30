class Solution {
public:
bool isPalindrome(int i,int j,string s){
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int helper(int i,string s,vector<int>& dp)
{
    if(i==s.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost=INT_MAX;
    for(int j=i;j<s.size();j++){
        if(isPalindrome(i,j,s)) cost=min(cost,1+helper(j+1,s,dp));
    }
    return dp[i]=cost;
}
    int minCut(string s) {
    vector<int> dp(s.size()+1,0);
    int n=s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
    for(int i=s.size()-1;i>=0;i--)
    {
        int cost=INT_MAX;
        for(int j=i;j<s.size();j++) if(pal[i][j]) cost=min(cost,1+dp[j+1]); 
        dp[i]=cost;
    }
    return dp[0]-1; 

    }
};