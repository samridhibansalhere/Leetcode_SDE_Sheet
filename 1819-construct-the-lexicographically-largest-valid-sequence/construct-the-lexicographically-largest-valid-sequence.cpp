class Solution {
public:
    vector<int> res;
    vector<bool> used;
    
    bool backtrack(int idx, int n) {
        if (idx == res.size()) return true;
        if (res[idx] != 0) return backtrack(idx + 1, n);
        
        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;
            
            int nextIdx = (num > 1) ? idx + num : idx;
            if (nextIdx < res.size() && res[nextIdx] == 0) {
                res[idx] = num;
                if (num > 1) res[nextIdx] = num;
                used[num] = true;

                if (backtrack(idx + 1, n)) return true;

                res[idx] = 0;
                if (num > 1) res[nextIdx] = 0;
                used[num] = false;
            }
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        res.assign(2 * n - 1, 0);
        used.assign(n + 1, false);
        backtrack(0, n);
        return res;
    }
};
