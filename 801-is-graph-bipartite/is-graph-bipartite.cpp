class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto neighbour:adj[node])
                    {
                        if(color[neighbour]==-1){color[neighbour]=1-color[node]; q.push(neighbour);}
                        else if (color[neighbour]==color[node])  return false;
                    }
                }
            }
        }
        return true;
    }
};