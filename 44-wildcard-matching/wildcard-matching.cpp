class Solution {
public:
    vector<vector<int>>dp;
    bool match(string &s, string &p, int m, int n) {
        
        if(m == 0) {
            for(int i = 0 ; i < n; i++) {
                if(p[i] == '*' ) {
                    continue;
                } else {
                    return false;
                }
            }

            return true;
        }

        if(n == 0) {
            return false;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        
        bool res = false;
        if(s[m-1] == p[n-1] || p[n-1] == '?') {
            res = match(s, p, m-1, n-1);
        } else if(p[n-1] == '*') {
            res = match(s,p,m-1,n) || match(s,p,m, n-1);
        }
        
        return dp[m][n] = res;
        
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp =  vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return match(s, p, s.size(), p.size());
    }
};