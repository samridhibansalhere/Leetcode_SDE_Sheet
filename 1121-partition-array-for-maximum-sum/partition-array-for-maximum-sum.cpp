class Solution {
public:
int f(int i,int k,vector<int>&arr,vector<int>&dp){
    if(i==arr.size())return 0;
    int len=0;
    int maxi=INT_MIN;
    int maxans=INT_MIN;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<min((int)arr.size(),i+k);j++)
    {
        len++;
        maxi=max(arr[j],maxi);
        int sum=len*maxi+f(j+1,k,arr,dp);
        maxans=max(maxans,sum);
    }
    return dp[i]=maxans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,k,arr,dp);
    }
};