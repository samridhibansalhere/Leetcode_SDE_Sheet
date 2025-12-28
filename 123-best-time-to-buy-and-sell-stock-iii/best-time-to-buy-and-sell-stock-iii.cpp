class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(5,0);
        vector<int> prev(5,0);
        long long profit=0;
        for(int index=n-1;index>=0;index--)
        {
                for(int transaction=0;transaction<4;transaction++)
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