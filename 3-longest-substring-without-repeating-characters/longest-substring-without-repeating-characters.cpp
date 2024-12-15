class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // Stores the last index of each character
        int l = 0, maxlen = 0;

        for (int r = 0; r < s.size(); r++) {
            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1; // Update the left pointer to avoid duplicates
            }
            hash[s[r]] = r; // Update the last seen index of the character
            maxlen = max(maxlen, r - l + 1); // Calculate the current max length
        }

        return maxlen;
    }
};
