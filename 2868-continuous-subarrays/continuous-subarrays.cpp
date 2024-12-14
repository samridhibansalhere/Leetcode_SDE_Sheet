#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int left = 0;

        deque<int> maxDeque; // To track maximum values
        deque<int> minDeque; // To track minimum values

        for (int right = 0; right < n; ++right) {
            // Update maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Update minDeque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Shrink the window if the condition is violated
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                left++;
            }

            // Add the number of valid subarrays ending at 'right'
            count += (right - left + 1);
        }

        return count;
    }
};
