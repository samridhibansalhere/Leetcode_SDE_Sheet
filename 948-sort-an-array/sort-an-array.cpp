class Solution {
public:
int func(vector<int>&nums,int low,int high){
    int pivotIndex = low + rand() % (high - low + 1);
    swap(nums[low], nums[pivotIndex]);
    int pivot=nums[low];
    int i=low,j=high;
    while(i<j)
    {
        while(i<=high && nums[i]<=pivot) i++;
        while(j>low && nums[j]>pivot) j--;
        if(i<j) swap(nums[i],nums[j]);
    }
    swap(nums[low],nums[j]);
    return j;
}
void quicksort(vector<int>&nums,int low,int high)
{
    if(low<high){
        int pivot=func(nums,low,high);
        quicksort(nums,low,pivot-1);
        quicksort(nums,pivot+1,high);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};