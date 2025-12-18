class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr) {
 vector<bool> prev(k+1,0),curr(k+1,0);
   prev[0]=true;
   curr[0]=true;
    if (arr[0] <= k) prev[arr[0]] = true;  
   for(int i=1;i<n;i++)
   {
      for(int j=1;j<=k;j++)
      {
         curr[j]=prev[j];
         if(j>=arr[i]) curr[j]= curr[j] || prev[j-arr[i]];
      }
      prev=curr;
   }
   return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++) total+=nums[i];
        if(total % 2==1) return 0;
        return subsetSumToK(nums.size(),total/2,nums);
    }
};