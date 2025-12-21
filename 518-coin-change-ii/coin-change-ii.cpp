class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
       const int MOD=INT_MAX;
       vector<long long> prev(amount+1,0),curr(amount+1,0);
       sort(coins.begin(),coins.end());
       prev[0]=curr[0]=1;
       for(int i=0;i<=amount;i++)
       if(i%coins[0]==0) prev[i]=curr[i]=1;
       for(int i=1;i<n;i++)
        {
            fill(curr.begin(), curr.end(), 0);
            curr[0] = 1;
            for(int j=0;j<=amount;j++){
                long long nottake=prev[j];
                long long take=0;
                if(j>=coins[i]) take=curr[j-coins[i]];
                curr[j]=(nottake+take)%MOD;
                }
            prev=curr;
       }
       return (int) prev[amount];
    }
};