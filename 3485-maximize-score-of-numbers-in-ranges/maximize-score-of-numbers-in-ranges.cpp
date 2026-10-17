class Solution {
public:
    bool isValid(int diff, vector<int>& a, int d) {
        long long lastChoosen  = a[0];
        for(int i = 1; i < a.size(); i++) {
            long long curVal = lastChoosen + diff;
            if(curVal >= a[i] && curVal <= a[i]+d) {
                lastChoosen = curVal;
            } else if(curVal < a[i]) {
                lastChoosen = a[i];
            }
            else {
                return false;
            }

            
        }

        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        /*
        6 8
        0 2
        3 5 

        0 2
        3 5
        6 8 
        */
        
        sort(start.begin(), start.end());
        int low = 0, high = start.back()+d - start[0];

        int res = -1;
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isValid(mid, start, d)) {
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return res;
    } 
};