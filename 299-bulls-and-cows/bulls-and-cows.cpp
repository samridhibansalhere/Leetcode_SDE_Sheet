class Solution {
public:
    string getHint(string secret, string guess) {
      int n=secret.size();
      int a=0;
      map<char,int> m1;
      map<char,int> m2;
      for(int i=0;i<n;i++)
      {
        if(secret[i]==guess[i]) a++;
        else {
            m1[secret[i]]++;
            m2[guess[i]]++;
        }
      }
      int c=0;  
      for(auto i:m1)
      {
        if(m2.find(i.first)!=m2.end()) c+=min(m1[i.first],m2[i.first]);
      }
      return to_string(a)+"A"+to_string(c)+"B";
    }
};