class Solution {
public:
double gain(int pass,int total)
{
    return (double)(pass+1)/(total+1)-(double)pass/total;
}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto c:classes)
        {
            int pass=c[0];
            int total=c[1];
            pq.push({gain(pass,total),{c[0],c[1]}});
        }
        while(extraStudents--){
            auto [a,b]=pq.top();
            pq.pop();
            int p=b.first;
            int t=b.second;
            pq.push({gain(p+1,t+1),{p+1,t+1}});
        }
        double sum=0;
        while(!pq.empty()){
            auto [a,b]=pq.top();
            sum+=(double)b.first/b.second;
            pq.pop();
        }
        return (double)sum/n;
    }
};