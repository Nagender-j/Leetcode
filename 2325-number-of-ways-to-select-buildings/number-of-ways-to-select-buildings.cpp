class Solution {
public:
    long long dp[100001][5][4];
    long long solve(int i, int cnt, string &s, char prevChoosen) {

        if(i == 0) {
            if(cnt == 0) return 1;
            return 0;
        }

        if(cnt < 0) return 0;

        int idx = prevChoosen - '0';
        // cout<< idx<<endl;
        if(dp[i][cnt][idx] != -1) return dp[i][cnt][idx];
        long long res = 0;
        if(prevChoosen != s[i-1]) {
            res += solve(i-1, cnt-1, s, s[i-1]) + solve(i-1, cnt, s, prevChoosen);
        } else {
            res += solve(i-1, cnt, s, prevChoosen);
        }       

        return dp[i][cnt][idx] = res;

    }
    long long numberOfWays(string s) {
        memset(dp, -1,sizeof(dp));
        return solve(s.size(), 3, s, '2');
    }
};