class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v]=weight;
            dist[v][u]=weight;
        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==1e9 || dist[k][j]==1e9)continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cntcity=n;
        int cityno=-1;
        for(int city=0;city<n;city++)
        {
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++)
            {
                if(dist[city][adjcity]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntcity)
            {
                cntcity=cnt;
                cityno=city;
            }
        }
        return cityno;
    }
};
