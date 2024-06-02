#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int maxAmount = amount + 1;
        vector<int> dp(amount + 1, maxAmount);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == maxAmount ? -1 : dp[amount];
    }
};
