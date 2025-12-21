class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);
    
        prev[0] = 1;
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            curr[0] = 1;
            for (int j = 1; j <= amount; j++) {
                long long nottake = prev[j];
                long long take = (j >= coins[i]) ? curr[j - coins[i]] : 0;
                curr[j] = (nottake + take)%INT_MAX;
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};
