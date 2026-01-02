class Solution {
public:
void dfs(int node,int n,vector<int>& visited,vector<vector<int>>& mat){
    if(!visited[node]){
        visited[node]=1;
        for(int i=0;i<n;i++)
        {
            if(mat[node][i]==1) dfs(i,n,visited,mat);
        }
    }
}
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int> visited(n+1,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,n,visited,mat);
                count++;
            }
        }
        return count;
    }
};