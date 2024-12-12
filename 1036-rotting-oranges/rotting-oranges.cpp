class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int c=0;
      queue<pair<int,int>> q;
      
      vector<vector<int>> visited(n,vector<int>(m,0)); 
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){ q.push(make_pair(i,j)); visited[i][j]=1;}
            else if(grid[i][j]==1) c++;
        }
      } 
      int t=0;
      while(!q.empty() && c>0)
      {
        int size=q.size();
        for(int i=0;i<size;i++){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x-1>=0 && grid[x-1][y]==1 && visited[x-1][y]==0){visited[x-1][y]=1; grid[x-1][y]=2; q.push(make_pair(x-1,y)); c--;}
            if(x+1<n && grid[x+1][y]==1 && visited[x+1][y]==0){visited[x+1][y]=1; grid[x+1][y]=2; q.push(make_pair(x+1,y)); c--;}
            if(y-1>=0 && grid[x][y-1]==1 && visited[x][y-1]==0){visited[x][y-1]=1; grid[x][y-1]=2; q.push(make_pair(x,y-1)); c--;}
            if(y+1<m && grid[x][y+1]==1 && visited[x][y+1]==0){visited[x][y+1]=1; grid[x][y+1]=2; q.push(make_pair(x,y+1)); c--;}
        }
        t++;
      }
      if(c==0) return t;
      else return -1;
    }
};