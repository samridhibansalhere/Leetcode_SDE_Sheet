class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
   int n=arr.size();
   int sum=0;
   for(int i=0;i<n;i++) sum+=arr[i];
   if(sum < d) return 0;
    if((sum - d) % 2 != 0) return 0;
   int k=(sum-d)/2;
   const int MOD = 1e9 + 7;
    vector<vector<long long>> dp(n,vector<long long>(k+1,0)); 
    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++) { 
        for(int j=0;j<=k;j++) { 
            long long nottake=dp[i-1][j]; 
            long long take=0; 
            if(arr[i]<=j) 
                take=dp[i-1][j-arr[i]]; 
            dp[i][j]=(take+nottake)%MOD; 
        } 
    } 
    return (int)dp[n-1][k]; 
    }
};