class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
       
        for(int i = 0 ; i < n; i++ ) {
            map<double , int> slopes;
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j < n; j++) {
                // int m = getSlope(points[i], points[j])
                
                int x2 = points[j][0], y2 = points[j][1];
                double m = 0;
                if(x2 == x1) {
                    m = 1e14;
                } else {
                    m = 1.0*(y2-y1)/(x2-x1);
                }
                
                slopes[m]++;
                res = max(res, slopes[m]);
            }
        }

        return res+1;
    }
};