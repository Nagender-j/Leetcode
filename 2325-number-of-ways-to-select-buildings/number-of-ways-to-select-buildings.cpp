class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        int totalZeros = 0;
        for(char c : s) {
            if(c == '0') {
                totalZeros++;
            }
        }

        int totalOnes = n - totalZeros;
        int zerosBefore = 0;
        int onesBefore = 0;
        long long res = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                int zerosAfter = totalZeros - zerosBefore;
                res += zerosBefore*1LL*zerosAfter;
                onesBefore++;
            } else {
                int onesAfter = totalOnes - onesBefore;
                res += onesBefore * 1LL * onesAfter;
                zerosBefore++;
            }

            
        }

        return  res;
    }
};