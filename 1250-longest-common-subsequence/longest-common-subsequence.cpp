class Solution {
public:
int helper(int index1,int index2,string text1,string text2, vector<vector<int>>& dp){
    if(index1<0 || index2<0) return 0;
    if(dp[index1][index2]!=-1) return dp[index1][index2];
    if(text1[index1]==text2[index2]) return dp[index1][index2]=1+helper(index1-1,index2-1,text1,text2,dp);
    else return dp[index1][index2]=max(helper(index1-1,index2,text1,text2,dp),helper(index1,index2-1,text1,text2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> curr(text2.size()+1,0);
        vector<int> prev(text2.size()+1,0);
        for(int i=0;i<=text1.size();i++) prev[0]=0;
        for(int j=0;j<=text2.size();j++) prev[j]=0;
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[text2.size()];
    }
};