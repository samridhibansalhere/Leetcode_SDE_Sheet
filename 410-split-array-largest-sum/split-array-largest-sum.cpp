class Solution {
public:
int func(vector<int>&arr,int cap)
{
    int ans=1,c=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]+c<=cap) c+=arr[i];
        else {ans++; c=arr[i];}
    }
    return ans;
}
    int splitArray(vector<int>& arr, int m) {
   int n=arr.size();
   if(m>n) return -1;
   int low=*max_element(arr.begin(),arr.end());
   int high=accumulate(arr.begin(),arr.end(),0);
   for(int i=m-1;i<n;i++)
   {
       high+=arr[i];
   }
   while(low<=high)
   {
       int mid=low+(high-low)/2;
       if(func(arr,mid)>m) low=mid+1;
       else high=mid-1;
   }
   return low;  
    }
};