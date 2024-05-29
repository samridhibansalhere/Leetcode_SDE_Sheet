#include <stack>
#include <string>
#include <sstream>

class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::stack<std::string> s;
        std::istringstream iss(preorder);
        std::string token;

        while (getline(iss, token, ',')) {
            while (token == "#" && !s.empty() && s.top() == "#") {
                s.pop();
                if (s.empty()) {
                    return false;
                }
                s.pop();
            }
            s.push(token);
        }

        return s.size() == 1 && s.top() == "#";
    }
};
