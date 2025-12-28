class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2*k+1,0);
        vector<int> prev(2*k+1,0);
        long long profit=0;
        for(int index=n-1;index>=0;index--)
        {
                for(int transaction=0;transaction<2*k;transaction++)
                {
                    if(transaction%2==0)
                    {
                        profit=max(prev[transaction],-prices[index]+prev[transaction+1]);
                    }
                    else
                    {
                        profit=max(prev[transaction],prices[index]+prev[transaction+1]);
                    } 
                    curr[transaction]=profit;
                }
            prev=curr;
        }
        return prev[0];
        }
};