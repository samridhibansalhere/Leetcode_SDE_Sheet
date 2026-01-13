class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
    vector<vector<long long>> adj(n,vector<long long>(n,1e9));
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]][edges[i][1]]=edges[i][2];
        adj[edges[i][1]][edges[i][0]]=edges[i][2];
    }
    for(int i=0;i<n;i++) adj[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][k] !=1e9 && adj[k][j] !=1e9) adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    int c=INT_MAX,ans=n-1;
    for(int i=n-1;i>=0;i--)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(i!=j && adj[i][j]<=d) count++;
        }
        if(count<c){c=count; ans=i;}
    }
    return ans;
    }
};