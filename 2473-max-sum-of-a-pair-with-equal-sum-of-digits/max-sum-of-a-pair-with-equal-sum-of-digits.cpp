#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(int n) {
        int c = 0;
        while (n != 0) {
            c += n % 10;
            n /= 10;
        }
        return c;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = -1;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int num : nums) {
            int sum = calc(num);

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, num + mp[sum]);
            }
            mp[sum] = max(mp[sum], num);
        }

        return maxi;
    }
};
