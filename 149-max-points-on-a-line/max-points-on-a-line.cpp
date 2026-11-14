class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;
        for(int i = 0 ; i < n; i++ ) {
            for(int j = i+1; j < n; j++) {
                // int m = getSlope(points[i], points[j]);

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                // y-y1 = m (x-x1);
                // points[i] = (x1, y1);
                int cres = 0;
                for(int k = 0 ; k < n; k++) {
                    int x = points[k][0], y = points[k][1];
                    if((y-y1) * (x2-x1) == (y2-y1) * (x-x1)) {
                        // x,y is on the same line
                        cres++;
                    }
                }

                res = max(res, cres);

            }
        }

        return res;
    }
};