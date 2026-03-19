class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int l=0,r=0,maxi=0;
      int z=0;
      while(r<nums.size())
      {
        if(nums[r]==0) z++;
        if(z>k){
            if(nums[l]==0) z--; 
            l++;
        }
        if(z<=k)maxi=max(maxi,r-l+1);
        r++; 
      }  
      return maxi;
    }
};