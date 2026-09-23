class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = a.size();
        vector<int>suffix(n+1, 0);

        map<int,int> suffixSumIdx;
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i+1] + a[i];
            if(suffixSumIdx.count(suffix[i]) == 0) {
                suffixSumIdx[suffix[i]] = i;
            }
        }

        int prefixSum = 0;
        int res = INT_MAX;
        if(suffixSumIdx.count(x)) {
            res = n - suffixSumIdx[x];
        }

        for(int i =0 ; i < n ;i++) {
            prefixSum += a[i];
            if(prefixSum == x) {
                res = min(res, i+1);
            }

            int remainingSum = x - prefixSum;
            if(suffixSumIdx.count(remainingSum)) {
                int j = suffixSumIdx[remainingSum];
                if(j <= i) continue;

                int front = i+1;
                int back = n - j;
                res = min(res, front + back);
            }
        }
        
        if(res == INT_MAX) return -1;
        return res;
    }
};