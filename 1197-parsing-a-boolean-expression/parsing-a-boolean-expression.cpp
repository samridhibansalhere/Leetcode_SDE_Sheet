class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',' ) continue;
            if (ch != ')') st.push(ch);
            else {
                bool istrue = false, isfalse = false;
                while (st.top() != '(') {
                    if (st.top() == 't') istrue = true;
                    if (st.top() == 'f') isfalse = true;
                    st.pop();
                }
                st.pop();              
                char op = st.top();    
                st.pop();
                if (op == '!') st.push(istrue ? 'f' : 't');
                else if (op == '&') st.push(isfalse ? 'f' : 't'); 
                else if (op == '|') st.push(istrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};
