class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
int c=0,x=0,y=s1.size()-1;
for(int i=0;i<s1.size();i++)
{
    if(s1[i]!=s2[i])
    {c++;
    if(c==1) x=i;
    if(c==2) y=i;
    }
}cout<<x<<y;
return (c==0)|| (c==2 && s1[x]==s2[y] && s2[x]==s1[y]);        
    }
};