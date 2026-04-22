class Solution {
public:
string base2(int n) { if(n == 0) return "0"; string res; while(n!=1) { if(n%2==1) res+='1'; else res+='0'; n=n/2; } reverse(res.begin(),res.end()); return res; }
    int bitwiseComplement(int n) {
        string s=base2(n);
        int c=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='0') c+=pow(2,s.size()-1-i);
        }
        return c;
    }
};