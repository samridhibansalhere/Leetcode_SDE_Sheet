class Solution {
public:
    bool isValid(string s, int target, int index, int sum) {
        if (index == s.length()) 
            return sum == target; 
        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0'); 
            if (isValid(s, target, i + 1, sum + num)) 
                return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (isValid(to_string(square), i, 0, 0)) 
                total += square;
        }
        return total;
    }
};
