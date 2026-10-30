class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
        int cnt = 0;

        // let n = x + (x+1) + (x+2) + (x+3) + ... + (x+ k-1)
        // when k = 1 , n = x
        // when k = 2, n = x+ x+1 
        // so on
        // n = kx + k*(k-1)*0.5 
        // n - k*(k-1)*0.5 = kx -> so that means if k exist and x exist then we get one combination
        for(int k = 1; k*(k-1)*0.5 < n; k++) {
            int x = n - k*(k-1)*0.5;
            if(x%k == 0) cnt++;
        }

        return cnt;
    }
};