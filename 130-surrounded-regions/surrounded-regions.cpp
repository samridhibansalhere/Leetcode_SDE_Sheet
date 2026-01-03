class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(grid[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){grid[i][j]='#'; q.push(make_pair(i,j)); visited[i][j]=1;}
        } 
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
                if(x-1>=0 && grid[x-1][y]=='O' && visited[x-1][y]==0){visited[x-1][y]=1; grid[x-1][y]='#'; q.push(make_pair(x-1,y));}
                if(x+1<n && grid[x+1][y]=='O' && visited[x+1][y]==0){visited[x+1][y]=1;grid[x+1][y]='#';q.push(make_pair(x+1,y)); }
                if(y-1>=0 && grid[x][y-1]=='O' && visited[x][y-1]==0){visited[x][y-1]=1; grid[x][y-1]='#'; q.push(make_pair(x,y-1)); }
                if(y+1<m && grid[x][y+1]=='O' && visited[x][y+1]==0){visited[x][y+1]=1; grid[x][y+1]='#'; q.push(make_pair(x,y+1));}
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                else if(grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }
};