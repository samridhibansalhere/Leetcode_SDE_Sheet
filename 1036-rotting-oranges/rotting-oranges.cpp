class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>> visited(n,vector<int>(m,0));
      queue<pair<int,int>> q;
      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) { 
        if(grid[i][j]==2) q.push({i,j}); 
        if(grid[i][j]==1) count++;
        }
      }
      if(count<=0) return 0;
      int time=-1;
      while(!q.empty())
      {
        int size=q.size();
        time++;
        while(size>0){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==0) {grid[i-1][j]=2; count--; visited[i-1][j]=1; q.push({i-1,j});}
        if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]==0) {grid[i][j-1]=2; count--; visited[i][j-1]=1; q.push({i,j-1});} 
        if(i+1<n && grid[i+1][j]==1 && visited[i+1][j]==0) {grid[i+1][j]=2; count--; visited[i+1][j]=1;q.push({i+1,j});} 
        if(j+1<m && grid[i][j+1]==1 && visited[i][j+1]==0) {grid[i][j+1]=2; count--; visited[i][j+1]=1;q.push({i,j+1});} 
        size--;
        }
      }
      if(count>0) return -1;
      else return time;
    }
};