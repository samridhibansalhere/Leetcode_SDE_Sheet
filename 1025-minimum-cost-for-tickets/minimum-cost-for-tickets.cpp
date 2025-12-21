class Solution{
public:
vector<int>dp;
int helper(int index,int n,vector<int>&days,vector<int>&costs){
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];
    int i=index;
    while(i<n&&days[i]<days[index]+1) i++;
    int c1=costs[0]+helper(i,n,days,costs);
    i=index;
    while(i<n&&days[i]<days[index]+7) i++;
    int c2=costs[1]+helper(i,n,days,costs);
    i=index;
    while(i<n&&days[i]<days[index]+30) i++;
    int c3=costs[2]+helper(i,n,days,costs);
    return dp[index]=min(c1,min(c2,c3));
}
int mincostTickets(vector<int>&days,vector<int>&costs){
    dp.assign(days.size(),-1);
    return helper(0,days.size(),days,costs);
}
};
