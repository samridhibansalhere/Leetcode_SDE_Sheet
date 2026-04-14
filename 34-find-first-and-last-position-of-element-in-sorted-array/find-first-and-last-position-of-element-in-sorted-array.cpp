class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int a=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int b=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(a==arr.size() || arr[a]!=x)a=-1;
        if(b-1>=0 && arr[b-1]!=x) b=0;
        return {a,b-1};
    }
};