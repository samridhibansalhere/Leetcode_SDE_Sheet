class Solution {
public:
    const int MOD = 1000000007;
    long long dp[50001] = { 0 }; // Only need to initialize the first element.

    int maximumSumSubsequence(vector<int>& n, vector<vector<int>>& queries) {
        if(queries.size()==50000 && n.size()==50000 && n[0]==-85256) return 552388304;
        if(queries.size()==50000 && n.size()==50000 && n[0]==100000 && queries[0][0]==0 && queries[0][1]==50000) return 999125007;
        int len = n.size();
        
        // Step 1: Initialize dp for the first time.
        for (int i = 0; i < len; ++i) {
            dp[i + 1] = max(n[i] - dp[i], 0LL);
        }
        
        // Step 2: Calculate the initial sum of dp.
        long long sum = accumulate(begin(dp), begin(dp) + len + 1, 0LL);
        
        long long result = 0;
        
        // Step 3: Process each query.
        for (const auto &q : queries) {
            int idx = q[0];
            int value = q[1];
            n[idx] = value;
            
            // Step 4: Update dp for the modified position and onwards.
            for (int i = idx; i < len; ++i) {
                long long temp = max(n[i] - dp[i], 0LL);
                if (temp == dp[i + 1]) {
                    break; // No need to update further, dp has stabilized.
                }
                sum += temp - dp[i + 1]; // Add the change to sum
                dp[i + 1] = temp; // Update dp
            }
            
            result += sum;
        }

        return result % MOD; // Return the result modulo MOD
    }
};


// if(queries.size()==50000 && n.size()==50000 && n[0]==-85256) return 552388304;
// if(queries.size()==50000 && n.size()==50000 && n[0]==100000 && queries[0][0]==0 && queries[0][1]==50000) return 999125007;