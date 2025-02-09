#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        long long totalPairs = 0; 
        long long goodPairs = 0; 

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i] - i;
            if (freqMap.find(key) != freqMap.end()) {
                goodPairs += freqMap[key];
            }
            freqMap[key]++;
            totalPairs += i; 
        }
        return totalPairs - goodPairs;
    }
};
