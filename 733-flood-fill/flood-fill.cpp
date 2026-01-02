class Solution {
public:
void dfs(int i,int j,int value,int color,int n,int m,vector<vector<int>> & visited,vector<vector<int>>& grid)
{
        visited[i][j]=1;
        grid[i][j]=color;
        if(i+1<n && grid[i+1][j]==value && visited[i+1][j]==0) dfs(i+1,j,value,color,n,m,visited,grid);
        if(i-1>=0 && grid[i-1][j]==value && visited[i-1][j]==0) dfs(i-1,j,value,color,n,m,visited,grid);
        if(j-1>=0 && grid[i][j-1]==value && visited[i][j-1]==0) dfs(i,j-1,value,color,n,m,visited,grid);
        if(j+1<m && grid[i][j+1]==value && visited[i][j+1]==0) dfs(i,j+1,value,color,n,m,visited,grid);
}
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int value=grid[sr][sc];
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        dfs(sr,sc,value,color,n,m,visited,grid);
        return grid;
    }
};