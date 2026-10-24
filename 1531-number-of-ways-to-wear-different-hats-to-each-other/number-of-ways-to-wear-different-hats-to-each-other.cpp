class Solution {
public:
int mod = 1e9+7;
    int dp[41][(1<<11) - 1];
    bool isSatisfied(int hat, vector<int> &preferences) {
        for(int i : preferences) {
            if(i == hat) return true;
        }

        return false;
    }

    int solve(int hat, vector<vector<int>>& hats, int mask) {
        
        int n = hats.size();
        int allGotMask = (1<<n) -1 ;

        if(mask == allGotMask) return 1;
        
        if(hat > 40) return 0;

        if(dp[hat][mask] != -1) return dp[hat][mask];

        long ways = 0;

        for(int i = 0 ; i < n; i++) {
            if((mask & (1<<i)) == 0) {
              if(isSatisfied(hat, hats[i])) {
                int newMask = mask | (1<<i);
                ways += solve(hat+1, hats, newMask);
                ways %= mod;
              }  
            } 
        }
        
        ways += solve(hat+1, hats, mask);
        ways %= mod;

        return dp[hat][mask] = ways;

        
    }

    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int mask = 0;
        memset(dp, -1,sizeof(dp));
        return solve(1,hats, mask);

        
    }
};