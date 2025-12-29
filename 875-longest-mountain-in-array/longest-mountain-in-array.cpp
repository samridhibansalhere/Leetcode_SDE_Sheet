class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> inc(n, 0), dec(n, 0);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                dec[i] = dec[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (inc[i] > 0 && dec[i] > 0) {
                ans = max(ans, inc[i] + dec[i] + 1);
            }
        }
        return ans;
    }
};
