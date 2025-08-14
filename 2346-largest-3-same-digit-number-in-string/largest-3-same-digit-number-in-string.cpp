class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> a = {"000","111","222","333","444","555","666","777","888","999"};
        for(int i=9;i>=0;i--){
            if(num.find(a[i])!=string::npos) return a[i];
        }
        return "";
    }
};
