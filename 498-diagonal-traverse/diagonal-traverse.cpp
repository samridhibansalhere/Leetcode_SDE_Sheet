class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> diagonals(m + n - 1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }
        
        vector<int> result;
        
        for (int k = 0; k < diagonals.size(); k++) {
            if (k % 2 == 0) {
                reverse(diagonals[k].begin(), diagonals[k].end());
            }
            for (int x : diagonals[k]) {
                result.push_back(x);
            }
        }
        
        return result;
    }
};
