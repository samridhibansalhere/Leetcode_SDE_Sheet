class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) free.push(i);
        priority_queue<pair<long long,int>, 
            vector<pair<long long,int>>, 
            greater<pair<long long,int>>> busy;
        vector<int> count(n,0);
        for(auto&i:meetings)
        {
            long long start=i[0],end=i[1];
            while(!busy.empty() && busy.top().first<=start)
            {
                free.push(busy.top().second);
                busy.pop();
            }
            if(!free.empty())
            {
                busy.push({end,free.top()});
                count[free.top()]++;
                free.pop();
            }
            else
            {
                busy.push({busy.top().first+end-start,busy.top().second});
                count[busy.top().second]++;
                busy.pop();
            }
        }
        int ans=0;
        for(int i=1;i<n;i++) if(count[i]>count[ans]) ans=i;
        return ans;
    }
};