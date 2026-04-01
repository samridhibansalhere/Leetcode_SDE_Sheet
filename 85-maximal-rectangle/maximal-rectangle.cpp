class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        stack<int> st;
        for(int i=0;i<heights.size()||!st.empty();i++)
        {
            while(!st.empty() && (i==heights.size() || heights[st.top()]>heights[i]))
            {
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,heights[element]*(nse-pse-1));
            }
            if(i<heights.size())st.push(i);
        }
        return maxi;
    }
    vector<vector<int>> prefixsum(vector<vector<char>> &matrix)
    {
        vector<vector<int>> c(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix[0].size();i++) 
        {
            if(matrix[0][i]=='0') c[0][i]=0;
            else c[0][i]=1;
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1') c[i][j]=c[i-1][j]+1;
                else c[i][j]=0;
            }
        }
        return c;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=0;
        vector<vector<int>> c=prefixsum(matrix);
        for(int i=0;i<c.size();i++)
        {
            maxi=max(maxi,largestRectangleArea(c[i]));
        }
        return maxi;
    }
};