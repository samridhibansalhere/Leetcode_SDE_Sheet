class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int> hash(256,-1);
      int l=0,r=0,maxlen=0;
      while(r<s.size())
      {
        if(hash[s[r]]>=l)
        {
            if(hash[s[r]]>=l)l=hash[s[r]]+1;
        }
        maxlen=max(maxlen,r-l+1);
        hash[s[r]]=r;
        r++;
      } 
      return maxlen; 
    }
};