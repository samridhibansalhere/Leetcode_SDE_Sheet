class Solution {
public:
int helper(int index,int k,int n,vector<int>& arr,vector<int>&dp){
    if(index==n) return 0;
    if(dp[index]!=-1) return dp[index];
    int len=0,maxi=INT_MIN,sum=INT_MIN;
    for(int j=index;j<min(index+k,n);j++){
        len++;
        maxi=max(maxi,arr[j]);
        sum=max(sum,len*maxi+helper(j+1,k,n,arr,dp));
    }
    return dp[index]=sum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return helper(0,k,n,arr,dp);
    }
};