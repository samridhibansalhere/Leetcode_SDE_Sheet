class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
vector<int> a(prices.size());
for(int k=0;k<prices.size();k++)
{
    a[k]=prices[k];
}
for(int i=0;i<prices.size();i++)
{
    for(int j=i+1;j<prices.size();j++)
    {
        if(prices[j]<=prices[i])
        {
            a[i]=prices[i]-prices[j];
            break;
        }
    }
}
return a;  
    }
};