class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty())
        {
            auto [d,p]=q.front();
            int i=p.first;
            int j=p.second;
            q.pop();
            if(j+1<m && grid[i][j+1]==0 && d+1<dist[i][j+1]){q.push({d+1,{i,j+1}}); dist[i][j+1]=d+1;}
            if(i+1<n && grid[i+1][j]==0 && d+1<dist[i+1][j]) {q.push({d+1,{i+1,j}});  dist[i+1][j]=d+1;}
            if(j+1<m && i+1<n && grid[i+1][j+1]==0 && d+1<dist[i+1][j+1]) {q.push({d+1,{i+1,j+1}});  dist[i+1][j+1]=d+1;}
            if(i-1>=0 && grid[i-1][j]==0 && d+1<dist[i-1][j]){q.push({d+1,{i-1,j}}); dist[i-1][j]=d+1;}
            if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0 && d+1<dist[i-1][j-1]){q.push({d+1,{i-1,j-1}}); dist[i-1][j-1]=d+1;}
            if(i-1>=0 && j+1<m && grid[i-1][j+1]==0 && d+1<dist[i-1][j+1]){q.push({d+1,{i-1,j+1}}); dist[i-1][j+1]=d+1;}
            if(j+1<m && grid[i][j+1]==0 && d+1<dist[i][j+1]){q.push({d+1,{i,j+1}}); dist[i][j+1]=d+1;}
            if(j-1>=0 && grid[i][j-1]==0 && d+1<dist[i][j-1]){q.push({d+1,{i,j-1}}); dist[i][j-1]=d+1;}
            if(i+1<n && j-1>=0 && grid[i+1][j-1]==0 && d+1<dist[i+1][j-1]){q.push({d+1,{i+1,j-1}}); dist[i+1][j-1]=d+1;}
        }
        return (dist[n-1][m-1]>=1e9)?-1:dist[n-1][m-1];
    }
};