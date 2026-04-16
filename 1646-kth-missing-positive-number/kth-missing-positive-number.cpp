class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>nums(n,0);
        for(int i=1;i<=n;i++)
        {
            nums[i-1]=arr[i-1]-i;
        }
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<k) low=mid+1;
            else high=mid-1;
        }
        if(high < 0) return k;
        return arr[high] + k - nums[high];
    }
};