class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
        int cnt = 0;
        for(int k = 1; k*(k-1)*0.5 < n; k++) {
            int x = n - k*(k-1)*0.5;
            if(x%k == 0) cnt++;
        }

        return cnt;
    }
};