class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> curr(n,0);
        for(int j=n-1;j>=0;j--)
        {
            curr[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int> next=curr;
            for(int j=i;j>=0;j--){
                int a=curr[j];
                int b=curr[j+1];
                next[j]=min(a,b)+triangle[i][j];
            }
            curr=next;
        }
        return curr[0];
    }
};