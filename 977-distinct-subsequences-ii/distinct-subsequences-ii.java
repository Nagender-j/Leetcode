class Solution {
    private final int mod = (int) 1e9+7;
    public int distinctSubseqII(String s) {
        int n = s.length();
        int[] last = new int[26];
        int[] dp = new int[n+1];
        Arrays.fill(last, -1);

        dp[0]  = 1;
       
        for(int i=1; i <=n; i++) {
            // dp[i-1] %= mod;
            dp[i] = dp[i-1]*2;
            dp[i] %= mod;
            int charPos = s.charAt(i-1) - 'a';
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
}