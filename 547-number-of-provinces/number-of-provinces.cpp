class Solution {
public:
 void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node) {
        visited[node] = 1; 
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !visited[i]) { 
                dfs(isConnected, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int c=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(isConnected,visited,i);
                c++;
            }
        }
        return c;
    }
};