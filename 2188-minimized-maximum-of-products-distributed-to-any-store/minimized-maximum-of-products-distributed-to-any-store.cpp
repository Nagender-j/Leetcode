class Solution {
public:
    bool isValid(long long mid, int k, vector<int>&a) {
        int curK = 0;
        
        for(int i : a) {
            int q = i/mid;
            int r = i%mid;
            curK += q;
            if(r != 0) {
                curK++;
            }
        }

        return curK <= k;
    }
    int minimizedMaximum(int n, vector<int>& a) {
        int m = a.size();
        long long low = 1, high = accumulate(a.begin(), a.end(), 0LL);
        long long res = -1;

        while(low <= high) {
            long long mid = low + (high-low)/2;
            if(isValid(mid, n, a)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return res;
    }
};