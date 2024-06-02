#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<int> stk;
        int third = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) return true;

            while (!stk.empty() && nums[i] > stk.top()) {
                third = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
