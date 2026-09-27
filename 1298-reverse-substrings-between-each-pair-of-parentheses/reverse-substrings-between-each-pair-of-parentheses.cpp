class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string cur = "";
        for(char c : s) {
            if(c == ')') {
                vector<char> chars;
                while(st.size() && st.top() != '(') {
                    char top = st.top(); st.pop();
                    chars.push_back(top);
                }
                if(st.size() != 0) {
                    st.pop();
                }
                for(int i = 0; i < chars.size(); i++) {
                    st.push(chars[i]);
                }
            } else {
                st.push(c);
            }
        } 
        
        string res = "";
        while(st.size()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};