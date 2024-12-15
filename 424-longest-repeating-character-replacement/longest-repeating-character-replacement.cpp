class Solution {
public:
    int characterReplacement(string s, int k) {
 vector<int> seen(26,0);
 int l=0,maxlen=0,maxi=0;
 for(int i=0;i<s.size();i++)
 {
    seen[s[i]-'A']++;
    maxi=max(maxi,seen[s[i]-'A']);
    int changes=i-l+1-maxi;
    if(changes>k)
    {
        seen[s[l]-'A']--;
        l++;
    }
    else maxlen=max(maxlen,i-l+1);
 }       
 return maxlen;
    }
};