class Solution {
public:
    int MOD = 1e9+7;
    int dp[101][101][101];
    int solve(vector<int> &a, int i, int cnt, int k) {
        if(k == 0) {
            int p = a.size() - cnt;
            return computePow(p);
        }
        
        if(i < 0) return 0;

        if(dp[i][cnt][k] != -1) return dp[i][cnt][k];
        long long res = 0 ;
        if(a[i] <= k) {
            res = solve(a, i-1, cnt+1, k-a[i]);
        }
        res %= MOD;
        res += solve(a, i-1, cnt, k);
        res  %= MOD;

        return dp[i][cnt][k] = res;

    }

    int computePow(int p) {
        long long res = 1;
        for(int i = 1; i <= p; i++) {
            res *= 2;
            res %= MOD;
        }

        return res;
    }
    int sumOfPower(vector<int>&a, int k) {
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        return solve(a, n-1, 0, k);    
    }
};