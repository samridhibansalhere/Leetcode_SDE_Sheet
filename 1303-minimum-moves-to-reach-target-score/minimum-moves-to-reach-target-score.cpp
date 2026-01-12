class Solution {
public:
    int minMoves(int target, int k) {
        int c = 0;

        while (target > 1 && k > 0) {
            if (target % 2 == 0) {
                target /= 2;
                k--;
            } else {
                target--;
            }
            c++;
        }
        if (target > 1) {
            c += target - 1;
        }

        return c;
    }
};
