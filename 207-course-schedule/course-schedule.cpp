class Solution {
public:
bool canFinish(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
	vector<int> indegree(n,0);
	for(int i=0;i<edges.size();i++)
	{
		adj[edges[i][1]].push_back(edges[i][0]);
		indegree[edges[i][0]]++;
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
		ans.push_back(node+1);
		q.pop();
		for(auto neighbour:adj[node])
		{
			indegree[neighbour]--;
			if(indegree[neighbour]==0) q.push(neighbour);
		}
	}
	
	return ans.size()==n;
}
};

