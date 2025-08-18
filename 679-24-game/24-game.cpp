class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(),cards.end());
        return solve(nums);
    }
    bool solve(vector<double>&nums){
        int n=nums.size();
        if(n==1 && fabs(nums[0]-24)<1e-6) return true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j){
                    vector<double> next;
                    for(int k=0;k<n;k++)
                    {
                        if(k!=i && k!=j) next.push_back(nums[k]);
                    }
                    for(double x:compute(nums[i],nums[j]))
                    {
                        next.push_back(x);
                        if(solve(next)) return true;
                        next.pop_back();
                    }
                }
            }
        }
     return false;   
    }
    vector<double> compute(double a,double b){
            vector<double> ans;
            ans.push_back(a+b);
            ans.push_back(a-b);
            ans.push_back(b-a);
            ans.push_back(a*b);
            if(fabs(b)>1e-6) ans.push_back(a/b);
            if(fabs(a)>1e-6) ans.push_back(b/a);
            return ans;
        }
};