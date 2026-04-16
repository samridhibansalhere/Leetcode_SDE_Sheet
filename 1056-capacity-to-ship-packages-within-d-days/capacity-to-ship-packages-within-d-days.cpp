class Solution {
public:
int func(vector<int>&nums,int w){
    int ans=1;
    int c=0;
    for(int i=0;i<nums.size();i++){
        if(c+nums[i]<=w) c+=nums[i];
        else {ans++; c=nums[i];}
    }
    return ans;
}
    int shipWithinDays(vector<int>& nums, int days) {
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        int low=*max_element(nums.begin(), nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long no=func(nums,mid);
            if(no>days) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};