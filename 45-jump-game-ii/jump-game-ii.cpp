class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,j=0;
        while(r<nums.size()-1)
        {
            int f=0;
            for(int index=l;index<=r;index++)
            {
                f=max(f,index+nums[index]);
            }
            l=r+1;
            r=f;
            j++;
        }
        return j;
    }
};