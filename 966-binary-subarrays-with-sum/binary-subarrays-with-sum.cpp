class Solution {
public:
    int help(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int l = 0, r = 0, currentSum = 0, count = 0;

        while (r < nums.size()) {
            currentSum += nums[r];

            // Adjust the left pointer to maintain the sum <= goal
            while (currentSum > goal && l <= r) {
                currentSum -= nums[l];
                l++;
            }

            // Count the subarrays with sum <= goal
            count += (r - l + 1);

            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums, goal) - help(nums, goal - 1);
    }
};
