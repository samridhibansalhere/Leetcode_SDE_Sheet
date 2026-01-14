class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty())
        {
            auto[d,i]=pq.top();
            pq.pop();
            if(visited[i]) continue;
            ans+=d;
            visited[i]=1;
            for(int j=0;j<n;j++){
                if(j!=i && visited[j]!=1) pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),j});
            }
        }
        return ans;
    }
};