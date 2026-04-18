class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int r=-1,maxi=-1;
            for(int i=0;i<n;i++)
            {
                if(maxi<mat[i][mid]) {maxi=mat[i][mid]; r=i;}
            }
            int left=(mid-1>=0)?mat[r][mid-1]:-1;
            int right=(mid+1<m)?mat[r][mid+1]:-1;
            if(left<mat[r][mid] && right<mat[r][mid]) return {r,mid};
            else if(left>mat[r][mid]) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};