struct interval {
    int start, end;
};

class Solution {
public:
    int dp[2001][2001];
    // compute all palindromes 
    int isPalindrome(int l, int r, string &s) {
        if(l > r) return 1;
        
        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] != s[r]) return dp[l][r] = 0;
        return dp[l][r] = isPalindrome(l+1, r-1, s);

    } 

    int maxPalindromes(string s, int k) {
        /*
         1. get all palindromes 
         2. then it is just max number of non overlapping intervals
         lets say intervals are [(1 3), (2, 5), (1,5) .....]
         then sort them by their end time and take the non overlapping overlapping one 
         greedy works here because taking earliest end will leave room for more numbers later 

         so we take earliest possible end 
        
        */
        
        memset(dp, -1, sizeof(dp));
        int n = s.size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n ; j++) {
                isPalindrome(i, j, s);
            }
        }

        return getAllPalindromes(n, k, s);
    
    }



    int getAllPalindromes(int n, int k,string s) {
        // just fix the j and see if there is any i, which gives me palindrome 
        // if yes then update the prev accoringly such that next palindrom won't overlap with prev
        int cnt = 0;
        int prev = -1;
        for(int j = k-1; j < n ; j++) {
            for(int i = j; i > prev ; i--) {
                if(j-i+1 < k) continue;
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