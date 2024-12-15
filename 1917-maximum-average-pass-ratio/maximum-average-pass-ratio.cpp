#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Define a max-heap with custom comparator for the potential gain
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;

        // Push all classes into the heap with their initial potential gains
        for (auto& c : classes) {
            maxHeap.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto [currentGain, classData] = maxHeap.top();
            maxHeap.pop();

            int pass = classData.first;
            int total = classData.second;

            // Add one extra student
            pass++;
            total++;

            // Push the updated class back into the heap
            maxHeap.push({gain(pass, total), {pass, total}});
        }

        // Calculate the final average pass ratio
        double totalAverage = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classData] = maxHeap.top();
            maxHeap.pop();
            totalAverage += (double)classData.first / classData.second;
        }

        return totalAverage / classes.size();
    }
};
