#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeZero(vector<int> nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) diff[r + 1] += val;
        }

        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += diff[i];
            nums[i] += current;
            if (nums[i] > 0) return false;  
        }
        return true;  
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeZero(nums, queries, mid)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
