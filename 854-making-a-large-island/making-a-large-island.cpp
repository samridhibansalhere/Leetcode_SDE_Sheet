class Solution {
public:
int ultimateparent(int node, vector<int>& parent)
{
    if (parent[node] == node) return parent[node];
    else return parent[node] = ultimateparent(parent[node], parent);
}

void unionbysize(int u, int v, vector<int>& size, vector<int>& parent)
{
    int node1 = ultimateparent(u, parent);
    int node2 = ultimateparent(v, parent);
    if (node1 == node2) return;

    if (size[node1] > size[node2]) {
        parent[node2] = node1;
        size[node1] += size[node2];
    } else {
        parent[node1] = node2;
        size[node2] += size[node1];
    }
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int result=0;
        vector<int> parent(n*n);
        vector<int>size(n*n,1);
        for(int i=0;i<n*n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                vector<int> dx={-1,0,1,0};
                vector<int> dy={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    int node1=i*n+j;
                    int node2=nr*n+nc;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1) unionbysize(node1,node2,size,parent);
                }
            }
        }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1) continue;
                    vector<int> dx={-1,0,1,0};
                    vector<int> dy={0,-1,0,1};
                    set<int> st;
                    int ans=1;
                    for(int k=0;k<4;k++){
                        int nr=i+dx[k];
                        int nc=j+dy[k];
                        int node1=i*n+j;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1) st.insert(ultimateparent(nr*n+nc,parent));
                    }
                    for(auto i:st) ans+=size[i];
                    result=max(result,ans);
            }
        }
        return max(result,size[ultimateparent(0,parent)]);
    }
};