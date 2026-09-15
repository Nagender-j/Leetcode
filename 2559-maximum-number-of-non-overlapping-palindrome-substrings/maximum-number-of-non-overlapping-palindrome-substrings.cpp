struct interval {
    int start, end;
};

class Solution {
public:
    int dp[2001][2001];
    int isPalindrome(int l, int r, string &s) {
        if(l >= r) return 1;
        
        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] != s[r]) return dp[l][r] = 0;
        return dp[l][r] = isPalindrome(l+1, r-1, s);

    } 
    int maxPalindromes(string s, int k) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n ; j++) {
                dp[i][j] = isPalindrome(i, j, s);
            }
        }

        return getAllPalindromes(n, k, s);
    
    }



    int getAllPalindromes(int n, int k,string s) {
        int cnt = 0;
        int prev = -1;
        for(int j = k-1; j < n ; j++) {
            for(int i = j-k+1; i > prev ; i--) {
                // if(j-i+1 < k) continue;
                if(dp[i][j] == 1) {
                    cnt++;
                    prev = j;
                    
                    break;
                
                }
            }
        }

        return cnt;
    }
};