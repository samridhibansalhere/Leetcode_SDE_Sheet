class Solution {
public:
long long func(vector<int>&nums,int mid)
{
    long long ans=0;
    for(int i=0;i<nums.size();i++)
    {
        ans+=(nums[i]+mid-1)/mid;
    }
    return ans;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long no=func(nums,mid);
            if(no>threshold) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};