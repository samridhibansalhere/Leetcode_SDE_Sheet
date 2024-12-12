class Solution {
public:
void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
    visited[i][j]=1;
        if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]=='1') dfs(grid,visited,i-1,j);
        if(i+1<grid.size() && visited[i+1][j]==0 && grid[i+1][j]=='1') dfs(grid,visited,i+1,j);
        if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]=='1') dfs(grid,visited,i,j-1);
        if(j+1<grid[0].size() && visited[i][j+1]==0 && grid[i][j+1]=='1') dfs(grid,visited,i,j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==0 and grid[i][j]=='1'){
                dfs(grid,visited,i,j);
                c++;
                }
            }
        }
        return c;
        
    }
};