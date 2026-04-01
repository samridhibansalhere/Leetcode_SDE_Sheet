class Solution {
public:
vector<int> nse(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> st;

    for(int i = nums.size()-1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        ans[i] = (!st.empty()) ? st.top() : nums.size();
        st.push(i);
    }
    return ans;
}
vector<int> pse(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> st;

    for(int i = 0; i < nums.size(); i++) {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        ans[i] = (!st.empty()) ? st.top() : -1;
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        vector<int> n=nse(heights);
        vector<int> p=pse(heights);
        for(int i=0;i<heights.size();i++)
        {
            maxi=max(maxi,heights[i]*(n[i]-p[i]-1));
        }
        return maxi;
    }
};