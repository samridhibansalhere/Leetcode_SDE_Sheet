class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int maxi=-1,r=-1,c=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maxi<mat[i][j]){maxi=mat[i][j]; r=i, c=j;}
            }
        }
        return {r,c};
    }
};