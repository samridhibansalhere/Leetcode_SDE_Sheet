class Solution {
public:
bool dfs(int node,vector<int>& color,vector<vector<int>>& adj)
{
    for(auto neighbour:adj[node])
    {
    if(color[neighbour]==-1){color[neighbour]=1-color[node]; if(!dfs(neighbour,color,adj)) return false;}
    else if (color[neighbour]==color[node])  return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs(i,color,adj)) return false;
            }
        }
        return true;
    }
};