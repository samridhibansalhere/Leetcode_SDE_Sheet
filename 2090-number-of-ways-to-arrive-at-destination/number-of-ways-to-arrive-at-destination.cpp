class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        const int MOD= 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto [d,node]=q.top();
            q.pop();
            for(auto [neighbour,weight]:adj[node])
            {
                if(dist[neighbour]==d+weight) ways[neighbour]=(ways[neighbour]%MOD+ways[node]%MOD)%MOD;
                else if(dist[neighbour]>d+weight){dist[neighbour]=d+weight; ways[neighbour]=ways[node]; q.push({d+weight,neighbour});}
            }
        }
        return ways[n-1];
    }
};