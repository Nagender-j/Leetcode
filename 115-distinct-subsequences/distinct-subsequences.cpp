class Solution {
public:
    int solve(string s, string t, int i, int j) {
        int m = s.size(), n = t.size();
        vector<unsigned int> prev(n+1), cur(n+1);
        for(int j = 0; j <= n; j++) {
            prev[j] = 0;
        }
        
        prev[0] = 1;
        cur[0] = 1;

        for(int i = 1 ; i <= s.size(); i++) {
            for(int j = 1; j <= t.size(); j++) {                
                if(s[i-1] == t[j-1]) {
                    cur[j] = prev[j-1] + prev[j];
                } else {
                    cur[j] =  prev[j];
                }
            }
            prev = cur;
        }
        
        return  cur[n];
    }
    int numDistinct(string s, string t) {
        return solve(s,t,s.size(), t.size());
    }
};