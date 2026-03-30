class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=0,total=0;
        int l=0,r=height.size()-1;
        while(l<r)
        {
            if(height[l]<height[r] && left>height[l]) {total+=left-height[l]; l=l+1;}
            else if(height[l]<height[r]){ left=height[l]; l=l+1;}
            else if(right>height[r]) {total+=right-height[r]; r=r-1;}
            else if(right<=height[r]){ right=height[r]; r=r-1;}
        }
        return total;
    }
};