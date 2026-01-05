class Solution {
public:
bool dfs(int node,vector<int>& visited,vector<int>& pathvisited,vector<vector<int>>& adj,vector<int> &safe){
  visited[node]=1;
  pathvisited[node]=1;
  for(auto neighbour:adj[node])
  {
    if(!visited[neighbour] && dfs(neighbour,visited,pathvisited,adj,safe)) return true;
    else if(pathvisited[neighbour]) return true;
  }
  pathvisited[node]=0;
  safe.push_back(node);
  return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> safe;
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) dfs(i,visited,pathvisited,adj,safe);
        }
        sort(safe.begin(),safe.end());
        return safe; 
    }
};
