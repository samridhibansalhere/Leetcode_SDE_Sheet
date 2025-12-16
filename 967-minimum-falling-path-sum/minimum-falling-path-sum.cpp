class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> curr(n,0);
        curr = matrix[n-1];  
        for (int i = n-2; i >= 0; i--) {
             vector<int> next=curr;
            for (int j = 0; j <n; j++) {
               
                int a=curr[j];
                int b=(j+1<n)?curr[j+1]:INT_MAX;
                int c=(j-1>=0)?curr[j-1]:INT_MAX;
                next[j] = min(a,min(b,c)) + matrix[i][j];
            }
            curr=next;
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            mini=min(mini,curr[j]);
        }
        return mini;
    }
};  
