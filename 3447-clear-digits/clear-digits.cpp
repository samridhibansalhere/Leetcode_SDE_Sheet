class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<int> a; 
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                a.push_back(i);
            }
        }
        while (!a.empty()) {
            int digit = a.front();
            a.erase(a.begin());         
            int leftNondigit = -1;
            for (int i = digit - 1; i >= 0; i--) {
                if (!(s[i] >= '0' && s[i] <= '9')) {
                    leftNondigit = i;
                    break;
                }
            }
            if (leftNondigit != -1) {
                s.erase(leftNondigit, 1);
                for (int &index : a) {
                    if (index > leftNondigit) {
                        index--;
                    }
                }
                digit--;
            }
            s.erase(digit, 1);
            for (int &index : a) {
                if (index > digit) {
                    index--;
                }
            }
        }

        return s;
    }
};
