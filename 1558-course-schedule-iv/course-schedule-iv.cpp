class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize the reachability matrix
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        
        // Step 2: Fill the direct prerequisites into the reachability matrix
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            reachable[prerequisite][course] = true;
        }
        
        // Step 3: Use Floyd-Warshall to calculate the transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }
        
        // Step 4: Answer the queries
        vector<bool> result;
        for (const auto& query : queries) {
            int course1 = query[0];
            int course2 = query[1];
            result.push_back(reachable[course2][course1]);
        }
        
        return result;
    }
};
