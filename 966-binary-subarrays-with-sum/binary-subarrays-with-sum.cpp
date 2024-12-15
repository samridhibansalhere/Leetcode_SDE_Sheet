class Solution {
public:
    int help(vector<int>& nums, int goal) {
        int l = 0, r = 0, max = 0, c = 0;

        while (r < nums.size()) {
            max += nums[r];

            while (max > goal && l <= r) {
                max -= nums[l];
                l++;
            }
                c += (r - l + 1);
            

            r++;
        }

        return c;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums, goal)-help(nums,goal-1);
    }
};
