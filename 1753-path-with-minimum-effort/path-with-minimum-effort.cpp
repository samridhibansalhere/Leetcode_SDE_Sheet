class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        while(!q.empty())
        {
            auto [l,p]=q.top();
            int i=p.first;
            int j=p.second;
            int d=grid[i][j];
            q.pop();
            if(j+1<m && max(l,abs(grid[i][j+1]-d))<dist[i][j+1]){dist[i][j+1]=max(l,abs(grid[i][j+1]-d)); q.push({dist[i][j+1],{i,j+1}});}
            if(i+1<n && max(l,abs(grid[i+1][j]-d))<dist[i+1][j]) {  dist[i+1][j]=max(l,abs(grid[i+1][j]-d)); q.push({dist[i+1][j],{i+1,j}});}
            if(i-1>=0 && max(l,abs(grid[i-1][j]-d))<dist[i-1][j]){ dist[i-1][j]=max(l,abs(grid[i-1][j]-d)); q.push({dist[i-1][j],{i-1,j}});}
            if(j-1>=0 && max(l,abs(grid[i][j-1]-d))<dist[i][j-1]){dist[i][j-1]=max(l,abs(grid[i][j-1]-d)); q.push({dist[i][j-1],{i,j-1}}); }
        }
        return dist[n-1][m-1];
    }
};