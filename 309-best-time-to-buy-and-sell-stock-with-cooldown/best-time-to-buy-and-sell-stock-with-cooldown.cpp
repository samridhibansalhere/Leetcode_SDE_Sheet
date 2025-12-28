class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2,0);
        vector<int> ahead(2,0);
        vector<int> ahead2(2,0);
        long long profit=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy) profit=max(-prices[index]+ahead[0],ahead[1]);
                else profit=max(prices[index]+ahead2[1],ahead[0]);
                curr[buy]=profit;
            }
            ahead2=ahead;
            ahead=curr;
        }
        return ahead[1];
        }
};