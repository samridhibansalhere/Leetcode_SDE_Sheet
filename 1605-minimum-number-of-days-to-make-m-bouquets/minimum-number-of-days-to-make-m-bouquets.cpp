class Solution {
public:
long long func(vector<int>&nums,int mid,int k)
{
    long long ans=0,c=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid) c=0;
        if(nums[i]<=mid) c++;
        if(c==k){ c=0; ans++;}
    }
    return ans;
}
    int minDays(vector<int>& nums, int m, int k) {
        if(1LL*m*k>nums.size()) return -1;
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long no=func(nums,mid,k);
            if(no>=m) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};