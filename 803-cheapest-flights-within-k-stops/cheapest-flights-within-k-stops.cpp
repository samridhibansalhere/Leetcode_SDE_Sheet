class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dest, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        dist[src]=0;
        q.push({0,{0,src}});
        while(!q.empty())
        {
            auto[stops,p]=q.front();
            q.pop();
            int d=p.first;
            int node=p.second;
            if(stops>k) continue;
            for(auto e:adj[node])
            {
                int neighbour=e.first;
                int path=e.second;
                if(d+path<dist[neighbour]  && stops<=k) {dist[neighbour]=d+path; q.push({stops+1,{d+path,neighbour}});}
            }
        }
        if(dist[dest]==1e9) return -1;
        else return dist[dest];
    }
};