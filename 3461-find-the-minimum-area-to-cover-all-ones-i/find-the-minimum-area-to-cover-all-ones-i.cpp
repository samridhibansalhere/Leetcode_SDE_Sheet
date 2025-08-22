class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int minr=n,maxr=-1,maxc=-1,minc=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minr=min(minr,i);
                    maxr=max(maxr,i);
                    maxc=max(maxc,j);
                    minc=min(minc,j);
                }
            }
        }

        int lenght=maxr-minr+1;
        int width=maxc-minc+1;
        return lenght*width;
    }
};