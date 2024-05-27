class Solution {
public:
    int specialArray(vector<int>& nums) {
sort(nums.begin(),nums.end());
int max=nums[nums.size()-1];
for(int j=0;j<=1000;j++)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>=j)
        {
            int c=nums.size()-i;
            if(c==j)return c;
            else break;
        }
    }
}
return -1;
    }
};