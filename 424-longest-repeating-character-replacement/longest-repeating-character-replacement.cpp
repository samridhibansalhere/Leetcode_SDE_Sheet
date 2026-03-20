class Solution {
public:
    int characterReplacement(string str, int k) {
    int l=0,r=0,maxi=0,maxlen=0;
    vector<int> v(26,0);
    while(r<str.size())
    {
        v[str[r]-'A']++;
        maxi=max(maxi,v[str[r]-'A']);
        if(r-l+1-maxi>k){
            v[str[l]-'A']--; 
            maxi=0;
            l++;
            for(auto i=0;i<26;i++) maxi=max(maxi,v[i]);
        }
        if(r-l-1-maxi<=k) maxlen=max(maxi,r-l+1);
        r++;
    }
    return maxlen;        
    }
};