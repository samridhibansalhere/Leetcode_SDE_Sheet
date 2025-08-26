class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        long long prev1=0,prev2=0;
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int b=dimensions[i][1];
            if(prev1<l*l+b*b)
            {   
                prev1=l*l+b*b;
                prev2=l*b;
            }
            else if(prev1==l*l+b*b && prev2<l*b) prev2=l*b;
        }
        return prev2;
    }
};