class Solution {
public:
    bool isValid(double mid, vector<int>& a, int k) {
        int curK = 0;
        for(int i=1; i < a.size(); i++) {
            int diff = a[i] - a[i-1];
            double count = diff/mid;
            curK += ceil(count)-1;

        }
        // if(curK <= k) {
        //     cout<<"valid mid : "<<mid<<endl;
        // }
        return curK <= k;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double low = 0, high = stations.back();
        double res = 0;
        while(high-low > 1e-6) {
            double mid = low+(high-low)*0.5;
            
           
            if(isValid(mid, stations, k)) {
                //  cout<<low<<" "<<high<< " "<<mid<< endl;
                res = mid;
                high = mid;
            } else {
                low = mid;
            }


        }

        return res;
    }
};