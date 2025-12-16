class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> curr(n,vector<int>(n,0));
        curr[n-1] = matrix[n-1];  
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <n; j++) {
                int a=curr[i+1][j];
                int b=(j+1<n)?curr[i+1][j+1]:INT_MAX;
                int c=(j-1>=0)?curr[i+1][j-1]:INT_MAX;
                curr[i][j] = min(a,min(b,c)) + matrix[i][j];
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            mini=min(mini,curr[0][j]);
        }
        return mini;
    }
};  
