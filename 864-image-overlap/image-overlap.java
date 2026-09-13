class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        
        int res = 0 ;
        for(int dx = -(n-1) ; dx <= n-1; dx++) { // because last row can move to atMax to first row -> n-1 -> 0 and similarly first row can shift to last row at max i.e 0 -> n-1 
            for(int dy = -(n-1) ; dy <= n-1; dy++) {
                int lres = 0;
                for(int i = 0 ; i < n; i++) {
                    for(int j = 0 ; j < n; j++) {
                        int ni = i+dx, nj = j+dy;
                        if(ni >=0 && ni < n && nj>=0 && nj < n && img1[i][j] == 1 && img2[ni][nj] == 1) {
                            lres++;
                            
                        }
                    }
                }

                 res = Math.max(res, lres);
                
               
            }
        }
        
        return res;
        
    }
}