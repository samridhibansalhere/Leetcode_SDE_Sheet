class Solution {
public:
    bool check(vector<int>& a, int t, int k) {
        for(int i = 0; i < a.size(); i++) {
            if(abs(t - a[i]) == k) return false;
        }
        return true;
    }

    void solve(int index, vector<int>& nums, int n, vector<int>& a, int k, int& c) {
        if(index == n){ c++; return;}
        //exclude
        solve(index + 1, nums, n, a, k, c);
        //include
        if(check(a, nums[index], k)) {
            a.push_back(nums[index]);
            solve(index + 1, nums, n, a, k, c);
            //backtrack
            a.pop_back();
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int c = 0;
        vector<int> a;
        solve(0, nums, n, a, k, c);
        return c-1;
    }
};
