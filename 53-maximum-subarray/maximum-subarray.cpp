class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        
        int maxSofar = a[0];
        int res = a[0];
    
        for(int i=1; i < a.size(); i++) {
            // take current number
            maxSofar = max(maxSofar+a[i], a[i]);
            res = max(res, maxSofar);
        }
        return res;   
    }
};