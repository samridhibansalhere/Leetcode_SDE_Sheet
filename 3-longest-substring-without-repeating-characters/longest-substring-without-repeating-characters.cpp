class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int l=0,r=0,maxi=0;
        while(r<s.size())
        {
            if(hash[s[r]]>=l) l=hash[s[r]]+1;
            maxi=max(maxi,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxi;
    }
};