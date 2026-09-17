class Solution {
public:
    bool isValid(int mid, int k, vector<int>& a) {
        int segments = 0;
        long long segSum  = 0;
        for(int i = 0; i < a.size(); i++) {
            segSum += a[i];
            if(segSum >= mid) {
                segments++;
                segSum = 0;
            }
        }

        return segments >= k+1;
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        long long low = 1 , high = accumulate(sweetness.begin(), sweetness.end(), 0LL);
        cout<<low << " "<<high<<endl;
        int res = 0;
        while(low <= high) {
            int mid = low+(high-low)/2;

            if(isValid(mid, k, sweetness)) {
                cout<<mid<<" "<<endl;
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return res;
    }
};