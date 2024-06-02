#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto i: words) {
            mp[i]++;
        }
        auto compare = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first < b.first; 
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> maxHeap(compare);
        for (const auto& entry : mp) {
            maxHeap.push({entry.second, entry.first});
        }
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
