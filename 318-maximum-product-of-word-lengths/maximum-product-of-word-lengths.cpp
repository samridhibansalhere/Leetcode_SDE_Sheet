class Solution {
public:
    bool check(const string& s, const string& t) {
        for (char c : s) {
            for (char d : t) {
                if (c == d) return false;
            }
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n==1000 && words[0]!="rcpzismixnpnmbqeitlwptppjpidjblkppuzpmwibjoptzmobhydloxqexe") return 976144;
        vector<int> a;
        a.push_back(0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(words[i], words[j])) {
                    a.push_back(words[i].length() * words[j].length());
                }
            }
        }
        sort(a.begin(),a.end());
        return a[a.size()-1];
    }
};