class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i=1,x=1,y=0;
        if(bills[0]!=5) return false;
        for(int i=1;i<bills.size();i++)
        {
            if(bills[i]==5) x++;
            else if(bills[i]==10){ x--; y++;}
            else if(bills[i]==20 && y>0){ x--; y--;}
            else if(bills[i]==20 && y==0) x-=3;
            if(x<0) return false;
        }
        return true;
    }
};