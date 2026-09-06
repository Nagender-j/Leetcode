class Solution {
public:
    int dp[1001][1001];
    int solve(string s, string t, int i, int j) {
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        // equal case
        if(s[i-1] == t[j-1]) {
            // take or not take
            res += solve(s, t, i-1, j-1) + solve(s, t, i-1, j);
        } else {
            res += solve(s, t, i-1, j);
        }
        
        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(s,t,s.size(), t.size());
    }
};