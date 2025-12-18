class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int c=grid[0].size(),r=grid.size();
    vector<vector<int>> curr(c, vector<int>(c, -1e9));
    vector<vector<int>> front(c, vector<int>(c, -1e9));
    for(int j1 = 0; j1 < c; j1++){
        for(int j2 = 0; j2 < c; j2++){
            if(j1 == j2)
                front[j1][j2] = grid[r-1][j1];
            else
                front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i = r-2; i >= 0; i--){
        for(int j1 = 0; j1 < c; j1++){
            for(int j2 = 0; j2 < c; j2++){

                long long maxi = -1e9;

                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){

                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if(nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c){

                            long long val = front[nj1][nj2];

                            if(j1 == j2)
                                val += grid[i][j1];
                            else
                                val += grid[i][j1] +(int) grid[i][j2];

                            maxi = max(maxi, val);
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front=curr;
    }

    return curr[0][c-1];
    }
};