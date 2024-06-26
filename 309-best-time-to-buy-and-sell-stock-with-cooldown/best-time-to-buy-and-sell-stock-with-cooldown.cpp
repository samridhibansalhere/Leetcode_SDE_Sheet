class Solution {
public:
    int solve(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        vector<int> cooldown(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[index] + next[0], 0 + next[1]);
                } else {
                    profit = max(prices[index] + cooldown[1], 0 + next[0]);
                }
                curr[buy] = profit;
            }
            cooldown = next;
            next = curr;   
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};