class Solution {
public:
    vector<char> getNextDigits(char c)
     {
        vector<char>res(2);
        if(c == '9') {
            res[0] = '0';
            res[1] = '8';
        } else if(c == '0') {
            res[0] = '1';
            res[1] = '9';
        } else {
            res[0] = c-1;
            res[1] = c+1;
        }
        
        return res;
    }
    int openLock(vector<string>& a, string target) {
        
        queue<string> q;
        q.push("0000");
        unordered_set<string>vis;
        unordered_set<string>deadends(a.begin(), a.end());
        vis.insert("0000");
        if(deadends.count("0000")) return -1;
        
        int level = 0;
        while(q.size()) {
            int sz  = q.size();
            while(sz--) {
                string s = q.front(); q.pop();
                if(s == target) return level;
                
                for(int i = 0 ; i < 4; i++) {
                    string next = s;
                    vector<char> nextDigits = getNextDigits(s[i]);
                    for(char c : nextDigits) {
                        next[i] = c;
                        if(vis.count(next) == 0 && deadends.count(next) == 0) {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};