class Solution {
public:
// bool dfs(int node,vector<int>& visited,vector<int>& pathvisited,vector<vector<int>>& adj,vector<int> &safe){
//   visited[node]=1;
//   pathvisited[node]=1;
//   for(auto neighbour:adj[node])
//   {
//     if(!visited[neighbour] && dfs(neighbour,visited,pathvisited,adj,safe)) return true;
//     else if(pathvisited[neighbour]) return true;
//   }
//   pathvisited[node]=0;
//   safe.push_back(node);
//   return false;
// }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<vector<int>> revadj(n);
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++)
	{
        indegree[i]=adj[i].size();
		for(int j=0;j<adj[i].size();j++)
        {
            revadj[adj[i][j]].push_back(i);
        }
	}
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0) q.push(i);
	}
	vector<int> ans;
	while(!q.empty())
	{
		int node=q.front();
		ans.push_back(node);
		q.pop();
		for(auto neighbour:revadj[node])
		{
			indegree[neighbour]--;
			if(indegree[neighbour]==0) q.push(neighbour);
		}
	}
    sort(ans.begin(),ans.end());
	return ans;
    }
};