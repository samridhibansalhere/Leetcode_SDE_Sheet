class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(grid[i][j]==0){ q.push(make_pair(i,j)); visited[i][j]=1;}
                else c++;
        } 
        while(!q.empty() && c>0)
        {
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x-1>=0 && grid[x-1][y]==1 && visited[x-1][y]==0){visited[x-1][y]=1; ans[x-1][y]=ans[x][y]+1; q.push(make_pair(x-1,y)); c--;}
                if(x+1<n && grid[x+1][y]==1 && visited[x+1][y]==0){visited[x+1][y]=1; ans[x+1][y]=ans[x][y]+1; q.push(make_pair(x+1,y)); c--;}
                if(y-1>=0 && grid[x][y-1]==1 && visited[x][y-1]==0){visited[x][y-1]=1; ans[x][y-1]=ans[x][y]+1; q.push(make_pair(x,y-1)); c--;}
                if(y+1<m && grid[x][y+1]==1 && visited[x][y+1]==0){visited[x][y+1]=1; ans[x][y+1]=ans[x][y]+1; q.push(make_pair(x,y+1)); c--;}
            }
        }
        return ans;
    }
};