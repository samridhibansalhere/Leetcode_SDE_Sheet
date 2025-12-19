class Solution {
public:
    bool backtrack(int idx, vector<int>& nums, vector<int>& bucket, int target)
    {
        if(idx == nums.size())
            return true;

        for(int i = 0; i < bucket.size(); i++)
        {
            if(bucket[i] + nums[idx] > target)
                continue;

            bucket[i] += nums[idx];
            if(backtrack(idx + 1, nums, bucket, target))
                return true;
            bucket[i] -= nums[idx];

            // pruning: avoid symmetric states
            if(bucket[i] == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        int target = sum / k;
        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target) return false;

        vector<int> bucket(k, 0);
        return backtrack(0, nums, bucket, target);
    }
};
