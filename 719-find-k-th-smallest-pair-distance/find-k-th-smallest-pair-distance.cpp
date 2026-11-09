class Solution {
public:
    int isValid(int mid, vector<int>& a, int k) {
        int cntK = 0;
        for(int i = 0 ; i < a.size(); i++) {
            int ai = a[i];
            int aj = mid+ai;
            // int j = i;
            // int low = i+1, high = a.size()-1;
            // while(low <= high) {
            //     int midj = low+(high-low)/2;
            //     if(a[midj] <= aj) {
            //         j = midj;
            //         low = midj+1;
            //     } else {
            //         high = midj - 1;
            //     }
            // }
            int j = upper_bound(a.begin(), a.end(), aj) - a.begin();
            j--;
           
            cntK += j-i;
        }

        return cntK >= k;
    }
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int low = 0, high = a.back() - a[0];
        int res = -1;
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isValid(mid, a, k)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
  
        }

        return res;
    }
};