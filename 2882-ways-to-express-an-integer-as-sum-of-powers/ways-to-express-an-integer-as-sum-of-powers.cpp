class Solution {
public:
const int m=1e9+7;
int helper(int n,int x,int c,vector<vector<int>>&dp)
{
    if(n==0) return 1;
    if(n<0) return 0;
    if(pow(c,x)>n) return 0;
    if(dp[n][c]!=-1) return dp[n][c];
    int v=pow(c,x);
    int take=helper(n-v,x,c+1,dp);
    int nottake=helper(n,x,c+1,dp);
    return dp[n][c]=(take+nottake)%m;
}
    int numberOfWays(int n, int x) {
        int cap=pow(n,1.0/x);
        vector<vector<int>> dp(n+1,vector<int>(cap+2,-1));
        return helper(n,x,1,dp);
    }
};