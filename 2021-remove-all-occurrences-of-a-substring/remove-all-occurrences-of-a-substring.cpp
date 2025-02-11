class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result; 
        int partSize = part.size();
        for (char c : s) {
            result.push_back(c); 
            if (result.size() >= partSize && result.substr(result.size() - partSize) == part) {
                result.erase(result.size() - partSize);
            }
        }
        return result;
    }
};
