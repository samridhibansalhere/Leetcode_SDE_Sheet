class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
     vector<vector<int>> res;
     int i=0;
     while(i<intervals.size() && intervals[i][1]<newinterval[0]){
        res.push_back({intervals[i][0],intervals[i][1]});
        i++;
     }
     while(i<intervals.size() && intervals[i][0]<=newinterval[1])
     {
        newinterval[0]=min(newinterval[0],intervals[i][0]);
        newinterval[1]=max(newinterval[1],intervals[i][1]);
        i++;
     }  
     res.push_back({newinterval[0],newinterval[1]});
     while(i<intervals.size()) {res.push_back({intervals[i][0],intervals[i][1]}); i++;}
     return res;
    }
};