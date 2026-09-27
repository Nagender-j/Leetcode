class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for(char c : s) {
            if(c == ')') {
    
                vector<string> stStrings;
                while(st.size() && st.top()[0] != '(') {
                    string top = st.top(); st.pop();
                    stStrings.push_back(top);
                }
                if(st.size() != 0) {
                    st.pop();
                }
                
                string cur = "";
                for(int i = stStrings.size() -1 ; i >= 0; i--) {
                    cur += stStrings[i];
                }
                reverse(cur.begin(), cur.end());
                st.push(cur);
                
            } else {
                string t = "";
                t.push_back(c);
                st.push(t);
                // cout<<t<<endl;
                // cout<<to_string(c)<<endl;
            }
        } 
        
        string res = "";
         vector<string> stStrings;
                while(st.size() ) {
                    string top = st.top(); st.pop();
                    stStrings.push_back(top);
                }
         string cur = "";
                for(int i = stStrings.size() -1 ; i >= 0; i--) {
                    cur += stStrings[i];
                }
        // reverse(res.begin(), res.end());
        return cur;
    }
};