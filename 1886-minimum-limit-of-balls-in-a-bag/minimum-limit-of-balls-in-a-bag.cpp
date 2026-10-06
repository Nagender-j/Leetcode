class Solution {
public:
    bool isValid(int mid, vector<int> &a, int k) {
        
        long long curK = 0;
        for(int i : a) {
            if(i > mid) {
                int q = i/mid;
                int r = i%mid;
                curK += (q-1);
                if(r != 0) curK++;
            }
        }

        return curK <= k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int res = -1;
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isValid(mid, nums, maxOperations)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return res;
    }

    
};