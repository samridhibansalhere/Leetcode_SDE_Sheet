class Solution {
public:
    int calc(const vector<int>& a) {
        int c = 0;
        for(int i : a) {
            c ^= i;
        }
        return c;
    }
    void solve(int index, vector<int>& nums, int n, vector<int>& a, int& c) {
        if(index == n) {
            c += calc(a);
            return;
        }
        solve(index + 1, nums, n, a, c);
        a.push_back(nums[index]);
        solve(index + 1, nums, n, a, c);
        a.pop_back();
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        vector<int> a; 
        solve(0, nums, n, a, c);
        return c; 
    }
};
