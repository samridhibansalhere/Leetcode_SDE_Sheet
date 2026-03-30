class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=i;
        }
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<nums2[i]) st.pop();
            if(mp.find(nums2[i])!=mp.end()) ans[mp[nums2[i]]]=(!st.empty())?st.top():-1;
            st.push(nums2[i]);
        }
        return ans;
    }
};