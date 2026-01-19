class Solution {
public:
int ultimateparent(int node, vector<int>& parent)
{
    if (parent[node] == node) return parent[node];
    else return parent[node] = ultimateparent(parent[node], parent);
}

void unionbyrank(int u, int v, vector<int>& rank, vector<int>& parent)
{
    int node1 = ultimateparent(u, parent);
    int node2 = ultimateparent(v, parent);
    if (node1 == node2) return;

    if (rank[node1] > rank[node2]) parent[node2] = node1;
    else if (rank[node1] < rank[node2]) parent[node1] = node2;
    else {
        parent[node1] = node2;
        rank[node2]++;
    }
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

    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size();
       vector<int> parent(n);
       vector<int> size(n,1);
       for(int i=0;i<n;i++) parent[i]=i;
       for(int i=0;i<n;i++)
       {
        for(int j=i+1;j<n;j++)
        {
            int rx=stones[i][0];
            int cx=stones[i][1];
            int ry=stones[j][0];
            int cy=stones[j][1];
            if(rx==ry || cx==cy) unionbysize(i,j,size,parent);
        }
       }
       int c=0;
       for(int i=0;i<n;i++) if(parent[i]==i) c++;
       return n-c;
    }
};