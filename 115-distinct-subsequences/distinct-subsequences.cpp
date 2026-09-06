class Solution {
public:
    vector<vector<unsigned int>>dp;
    int solve(string s, string t, int i, int j) {
        for(int i = 0 ; i <= s.size(); i++) {
            for(int j = 0; j <= t.size(); j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                if(i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                 
                
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }
        
        return  dp[s.size()][t.size()];
    }
    int numDistinct(string s, string t) {
        dp = vector<vector<unsigned int>>(s.size()+1, vector<unsigned int>(t.size()+1, -1));
        return solve(s,t,s.size(), t.size());
    }
};