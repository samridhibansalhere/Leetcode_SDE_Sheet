class Solution {
public:
bool check(string s,char a)
{
    for(auto i:s)
    {
        if(i==a) return false;
    }
    return true;
}
    int lengthOfLongestSubstring(string s) {
int n=s.size();
if(n==0) return 0;
if(n==1) return 1;
int len=0;
int ans=0;
string t="";
for(int i=0;i<n;i++)
{
    if(check(t,s[i])) t+=s[i];
    else 
    {
        int pos=t.find(s[i]);
        t=t.substr(pos+1)+s[i];
    }
    int p=t.size();
    len=max(p,len);
    ans=max(ans,len);
}
return ans;
    }
};