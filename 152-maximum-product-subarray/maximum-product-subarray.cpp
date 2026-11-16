class Solution {
public:
    int maxProduct(vector<int>& a) {
        
        int res = a[0];
        int maxSoFar = a[0];
        int minSoFar = a[0];
        
        for(int i = 1; i < a.size(); i++) {
          
            int tempMax = max({maxSoFar*a[i], minSoFar*a[i], a[i]});
            minSoFar = min({maxSoFar*a[i], minSoFar*a[i], a[i]});
            
            maxSoFar = tempMax;
            res = max(res, maxSoFar);
        }
        return res;
    }
};