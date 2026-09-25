class Solution {
public:

    vector<vector<string>> getAllSegment(string s) {
        vector<vector<string>>res;
      
        
        int n = s.size();
        for(int i = 0 ; i < n; ) {
            if(s[i] >= 'a' && s[i] <='z') {
                string curString = "";
                while(i < n && s[i] >= 'a' && s[i] <='z') {
                    curString += s[i];
                    i++;
                }
                res.push_back({curString});
            } else if(s[i] == '{') {
                i++;
                vector<string> cur;
                string curString = "";
                while(i< n) {
                    if(s[i] == ',') {
                        cur.push_back(curString);
                        curString = "";
                        i++;
                    } else if(s[i] == '}') {
                        cur.push_back(curString);
                        curString = "";
                        i++;
                        break;
                    } else {
                        curString += s[i];
                        i++;
                    }
                }
                res.push_back(cur);
            }
        }

        return res;
    }
    vector<string> expand(string s) {
        stack<vector<string>> st;
        int n = s.size();

        vector<vector<string>> segments = getAllSegment(s);

        vector<string> res = segments[0];
        for(int i = 1; i < segments.size(); i++) {
            vector<string> segment = segments[i];

            res = multiply(res, segment);
        }

        return res;
    }

    vector<string> multiply(vector<string> &a, vector<string> &b) {
        vector<string> res;
        for(string ai : a) {
            for(string bi : b) {
                res.push_back(ai+bi);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};