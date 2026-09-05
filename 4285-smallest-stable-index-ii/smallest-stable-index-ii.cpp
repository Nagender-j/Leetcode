class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n = a.size();
        vector<int> minToRight(n);
        int mn = a[n-1];
        for(int i = n-1; i >= 0; i--) {
             mn = min(a[i], mn);
            minToRight[i] = mn;
        }

        int mx = a[0];
        for(int i = 0; i < n; i++) {
            mx = max(a[i], mx);
            int score = mx - minToRight[i];
            if(score <= k) return i;
        }

        return -1;
    }
};