class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
int n=matrix.size();
vector<vector<int>> a=matrix;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        matrix[i][j]=a[n-j-1][i];
    }
}       
    }
};