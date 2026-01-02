class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int count=0;
       vector<int> ans={1,2,3,4,5,6,7,8,9};
       for(int i=0;i<n-2;i++) 
       {
        for(int j=0;j<m-2;j++)
        {
            int a=grid[i][j];
            int b=grid[i][j+1];
            int c=grid[i][j+2];
            int d=grid[i+1][j];
            int e=grid[i+1][j+1];
            int f=grid[i+1][j+2];
            int g=grid[i+2][j];
            int h=grid[i+2][j+1];
            int k=grid[i+2][j+2];
            vector<int> v = {a,b,c,d,e,f,g,h,k};
            sort(v.begin(), v.end());
            if(v != ans || e!=5) continue; 
            if(a+b+c == 15 && d+f == 10 && g+h+k == 15 && a+d+g == 15 && b+h == 10 && c+f+k == 15 && a+k == 10 && c+g == 10) count++;
        }
       }
       return count;
    }
};