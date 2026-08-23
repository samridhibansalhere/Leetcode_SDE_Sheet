class Solution {
public:
    int minBitFlips(int a, int b) {
        int n=a^b;
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i)) cnt++;
        }
        return cnt;
    }
};