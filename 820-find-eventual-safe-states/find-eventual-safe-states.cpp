class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<vector<int>> revadj(n);
	vector<int> indegree(n,0);
    queue<int> q;
	for(int i=0;i<n;i++)
	{
        indegree[i]=adj[i].size();
        if(indegree[i]==0) q.push(i);
		for(int j=0;j<adj[i].size();j++)
        {
            revadj[adj[i][j]].push_back(i);
        }
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