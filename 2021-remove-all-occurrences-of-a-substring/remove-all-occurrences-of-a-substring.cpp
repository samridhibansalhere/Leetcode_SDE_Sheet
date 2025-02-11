class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos = s.find(part);
        while (pos != string::npos) {
            s.erase(pos, part.size()); 
            pos = s.find(part); 
        }
        return s;
    }
};
