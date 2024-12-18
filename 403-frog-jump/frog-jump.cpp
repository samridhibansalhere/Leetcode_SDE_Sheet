class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n < 2) return true;
        if (stones[1] != 1) return false; // Frog can't reach the second stone.

        unordered_map<int, unordered_set<int>> dp; // stone_position -> possible jump sizes
        dp[0].insert(0); // Initialize starting position

        for (int i = 0; i < n; ++i) {
            int stonePos = stones[i];
            for (int jump : dp[stonePos]) {
                for (int step = jump - 1; step <= jump + 1; ++step) {
                    if (step > 0) { // Valid jump
                        int nextPos = stonePos + step;

                        // If the next position is the last stone, return true
                        if (nextPos == stones[n - 1]) {
                            return true;
                        }

                        // Only process valid stones
                        if (binary_search(stones.begin(), stones.end(), nextPos)) {
                            dp[nextPos].insert(step);
                        }
                    }
                }
            }
        }

        return false; // If we finish the loop without reaching the last stone
    }
};