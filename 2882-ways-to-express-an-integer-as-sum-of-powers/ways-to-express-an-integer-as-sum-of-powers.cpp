#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    unordered_map<long long, int> dp; 
    int helper(int n, int x, int curr) {
        if (n == 0) return 1;     
        if (n < 0) return 0;   
        long long key = ((long long)n << 20) | curr; 
        if (dp.count(key)) return dp[key];

        long long powVal = pow(curr, x);
        if (powVal > n) return dp[key] = 0;
        int take = helper(n - powVal, x, curr + 1);
        int skip = helper(n, x, curr + 1);
        return dp[key] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.clear();
        return helper(n, x, 1);
    }
};
