#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    bool noCommonChars(int mask1, int mask2) {
        return (mask1 & mask2) == 0;
    }

    int maxProduct(std::vector<std::string>& words) {
        int n = words.size();
        std::vector<int> masks(n, 0);
        std::vector<int> lengths(n, 0);

        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= 1 << (c - 'a');
            }
            masks[i] = mask;
            lengths[i] = words[i].length();
        }

        int maxProduct = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (noCommonChars(masks[i], masks[j])) {
                    maxProduct = std::max(maxProduct, lengths[i] * lengths[j]);
                }
            }
        }

        return maxProduct;
    }
};
