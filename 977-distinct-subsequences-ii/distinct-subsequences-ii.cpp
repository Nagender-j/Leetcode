class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>last(26, -1);
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        
        for(int i=1; i <=n; i++) {
            // dp[i-1] %= mod;
            dp[i] = (dp[i-1]%mod)*2;
            dp[i] %= mod;
            int charPos = s[i-1] - 'a';
            if(last[charPos] != -1) {
                dp[i] -= (dp[last[charPos]] % mod);
            }
            if(dp[i] < 0) dp[i] += mod;
            last[charPos] = i-1;
        }
        
        dp[n]--;
        if(dp[n] < 0) dp[n] += mod;
        

        return dp[n];
    }
};