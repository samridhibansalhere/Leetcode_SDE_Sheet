#include <vector>
#include <map>
#include <set>
#include <utility>

class Solution {
public:
    long long findScore(std::vector<int>& nums) {
        std::map<int, std::set<std::pair<int, bool>>> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].insert({i, false});
        }
        long long score = 0;
        for (auto& [value, indices] : m) {
            std::vector<std::pair<int, bool>> toReinsert; // Temporary storage for modified pairs
            for (auto it = indices.begin(); it != indices.end(); ++it) {
                auto [index, processed] = *it;
                if (!processed) {
                    // Add value to the score
                    score += value;

                    // Mark current index as processed
                    toReinsert.push_back({index, true});

                    // Mark neighbors as processed
                    if (index > 0) {
                        int leftValue = nums[index - 1];
                        auto& leftSet = m[leftValue];
                        auto leftIt = leftSet.find({index - 1, false});
                        if (leftIt != leftSet.end()) {
                            toReinsert.push_back({index - 1, true});
                            leftSet.erase(leftIt);
                        }
                    }
                    if (index < nums.size() - 1) {
                        int rightValue = nums[index + 1];
                        auto& rightSet = m[rightValue];
                        auto rightIt = rightSet.find({index + 1, false});
                        if (rightIt != rightSet.end()) {
                            toReinsert.push_back({index + 1, true});
                            rightSet.erase(rightIt);
                        }
                    }
                }
            }
            // Reinsert modified pairs into the set
            for (const auto& pair : toReinsert) {
                indices.insert(pair);
            }
        }

        return score;
    }
};
