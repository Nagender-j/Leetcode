class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        int res = 0;
       
        for(int i = 0 ; i < n; i++ ) {
            Map<Double , Integer> slopes = new HashMap<>();
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j < n; j++) {
                // int m = getSlope(points[i], points[j])
                
                int x2 = points[j][0], y2 = points[j][1];
                double m = 0;
                if(x2 == x1) {
                    m = Double.MAX_VALUE;
                } else {
                    m = 1.0*(y2-y1)/(x2-x1);
                }

                System.out.println(i+" "+j+ " "+m);
                if(m == -0.0) {
                    m = 0;
                }
                slopes.put(m, slopes.getOrDefault(m, 0)+1);
                res = Math.max(res, slopes.get(m));
                System.out.println(res);
                
            }
        }

        return res+1;
    }
}