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
            curr[1]=max(-prices[index]+ahead[0],ahead[1]);
            curr[0]=max(prices[index]+ahead2[1],ahead[0]);
            ahead2=ahead;
            ahead=curr;
        }
        return curr[1];
        }
};