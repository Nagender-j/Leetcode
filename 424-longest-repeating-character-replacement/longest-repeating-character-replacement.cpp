class Solution {
public:

    int solve(string s, int k, char c) {
        int i = 0, j = 0, n = s.size();
        int curK = 0;
        int res = k;
        while(j < n) {
            if(s[j] == c) {
                res = max(j-i+1, res);
                j++;
               
            } else {
                while(i< n && curK >= k) {
                    if(s[i] != c) {
                      
                        curK--;
                    }
                    i++;
                }

                res = max(res, j-i+1);
                curK++;
                j++;
                
            }

            
        }

        return res;
    }
    int characterReplacement(string s, int k) {
        
        int res = k;
        for(char c='A'; c <='Z'; c++) {
            res = max(res, solve(s, k, c));
        }

        return res;
    }
};