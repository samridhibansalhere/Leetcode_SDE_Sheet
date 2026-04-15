class Solution {
public:
long long func(vector<int>&piles,int cap)
{
    long long ans=0;
    for(int i=0;i<piles.size();i++)
    {
        if(piles[i]%cap==0) ans+=piles[i]/cap;
        else ans+=piles[i]/cap+1;
    }
    return ans;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1;
        int high=piles[piles.size()-1];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long time=func(piles,mid);
            if(time<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};