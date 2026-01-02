class Solution {
public:
void dfs(int i,int j,int n,int m,vector<vector<int>> & visited,vector<vector<char>>& grid)
{
    if(!visited[i][j] && grid[i][j]=='1')
    {
        visited[i][j]=1;
        if(i+1<n ) dfs(i+1,j,n,m,visited,grid);
        if(i-1>=0) dfs(i-1,j,n,m,visited,grid);
        if(j-1>=0) dfs(i,j-1,n,m,visited,grid);
        if(j+1<m) dfs(i,j+1,n,m,visited,grid);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(i,j,n,m,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};