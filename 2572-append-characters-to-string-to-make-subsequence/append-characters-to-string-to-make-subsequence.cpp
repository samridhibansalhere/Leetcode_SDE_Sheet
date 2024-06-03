class Solution {
public:
    int appendCharacters(string s, string t) {
        int k = 0; 
        for (int i = 0; i < t.size(); i++) {
            while (k < s.size() && s[k] != t[i]) {
                k++;
            }
            if (k < s.size() && s[k] == t[i]) {
                k++; 
            } else {
                return t.size() - i; 
            }
        }
        return 0; 
    }
};
