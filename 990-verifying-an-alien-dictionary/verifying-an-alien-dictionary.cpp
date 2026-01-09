class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
    int n=words.size();
   for(int i=0;i<n-1;i++)
   {
       string s1=words[i];
       string s2=words[i+1];
       int len=min(s1.size(),s2.size());
       bool found=false;
       for(int j=0;j<len;j++)
       {
           if (s1[j]!=s2[j]){
                int x=0,y=0;
                for(int k=0;k<order.size();k++)
                {
                    if(order[k]==s1[j]) x=k;
                    if(order[k]==s2[j]) y=k;
                }
                if(x>y) return false;
                found=true;
                break;
            }   
       }
        if(found==false && s1.size()>s2.size()) return false;
   }
return true;
}
};