#include <stack>
#include <string>
#include <sstream>

class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        stack<string> st;
        istringstream s(preorder);
        string token;

        while (getline(s, token, ','))
        {
            while (token == "#" && !st.empty() && st.top() == "#")
            {
                st.pop();
                if (st.empty()) return false;
                st.pop();
            }
            st.push(token);
        }

        return st.size() == 1 && st.top() == "#";
    }
};