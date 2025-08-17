class Solution {
public:
    double new21Game(int n, int k, int maxi) {
        if(k==0 || n>=k-1+maxi) return 1.0;
        vector<double> dp(n+1,0.0);
        double windowsize=1.0,result=0.0;
        dp[0]=1.0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=windowsize/maxi;
            if(i<k) windowsize+=dp[i];
            else result+=dp[i];
            if(i-maxi>=0) windowsize-=dp[i-maxi];
        } 
        return result;
    }
};