class Solution {
public:
void dfs(int node,int parent,int &timer,vector<int>&visited,vector<int>&first,vector<int>&low,vector<vector<int>>&ans,vector<vector<int>>&adj){
    visited[node]=1;
    first[node]=low[node]=timer;
    timer++;
    for(auto i:adj[node]){
        if(i==parent) continue;
        if(!visited[i]){
            dfs(i,node,timer,visited,first,low,ans,adj);
            low[node]=min(low[node],low[i]);
            if(first[node]<low[i]) ans.push_back({node,i});
        } 
        else low[node]=min(low[node],low[i]);
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int timer=1;
        vector<int>visited(n,0);
        vector<int> first(n,0);
        vector<int> low(n,0);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) dfs(i,-1,timer,visited,first,low,ans,adj);
        }
        return ans;
    }
};