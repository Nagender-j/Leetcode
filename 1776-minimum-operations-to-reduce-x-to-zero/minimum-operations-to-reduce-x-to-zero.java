class Solution {
    public int minOperations(int[] a, int x) {
        int n = a.length;
        
        int[] suffix = new int[n+1];

        Map<Integer, Integer> suffixSumIdx = new HashMap<>();
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i+1] + a[i];
            if(!suffixSumIdx.containsKey(suffix[i])) {
                suffixSumIdx.put(suffix[i],i);
            }
        }

        int prefixSum = 0;
        int res = Integer.MAX_VALUE;
        if(suffixSumIdx.containsKey(x)) {
            res = n - suffixSumIdx.get(x);
        }

        for(int i =0 ; i < n ;i++) {
            prefixSum += a[i];
            if(prefixSum == x) {
                res = Math.min(res, i+1);
            }

            int remainingSum = x - prefixSum;
            if(suffixSumIdx.containsKey(remainingSum)) {
                int j = suffixSumIdx.get(remainingSum);
                if(j <= i) continue;

                int front = i+1;
                int back = n - j;
                res = Math.min(res, front + back);
            }
        }
        
        if(res == Integer.MAX_VALUE) return -1;
        return res;
        
    }
}