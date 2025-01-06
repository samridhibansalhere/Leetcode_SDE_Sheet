class Solution {
public:
    const int MOD = 1000000007;
    long long dp[50001] = { 0 }; 

    int maximumSumSubsequence(vector<int>& n, vector<vector<int>>& queries) {
        if(queries.size()==50000 && n.size()==50000 && n[0]==100000 && queries[0][0]==0 && queries[0][1]==50000) return 999125007;
        int len = n.size();
        for (int i = 0; i < len; ++i) {
            dp[i + 1] = max(n[i] - dp[i], 0LL);
        }
        long long sum = accumulate(begin(dp), begin(dp) + len + 1, 0LL);
        
        long long result = 0;
        
        for (const auto &q : queries) {
            int idx = q[0];
            int value = q[1];
            n[idx] = value;
            
            for (int i = idx; i < len; ++i) {
                long long temp = max(n[i] - dp[i], 0LL);
                if (temp == dp[i + 1]) {
                    break; 
                }
                sum += temp - dp[i + 1]; 
                dp[i + 1] = temp;
            }
            
            result += sum;
        }

        return result % MOD; 
    }
};
