class Solution {
    int inf = (int)1e8;
    int dx[] = new int[]{0, 1, 0, -1};
    int dy[] = new int[]{1, 0, -1, 0};

    public int minimumEffortPath(int[][] heights) {
        
        int m = heights.length;
        int n = heights[0].length;

        int[][] dist = new int[m][n];
        for(int i = 0; i < m; i++) {
            Arrays.fill(dist[i], inf);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, 0, 0}); 
        dist[0][0] = 0;
        
        while(!pq.isEmpty()) {
            int[] node = pq.poll();
            int pathAbsDiff = node[0], x = node[1], y = node[2];
            if(dist[x][y] < pathAbsDiff) continue;

            for(int dir = 0 ; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx>=0 && nx<m && ny>=0 && ny<n) {
                    int curAbsDiff = Math.max(pathAbsDiff, Math.abs(heights[nx][ny] - heights[x][y]));
                    if(dist[nx][ny] > curAbsDiff) {
                        dist[nx][ny] = curAbsDiff;
                        pq.offer(new int[]{curAbsDiff, nx, ny});
                        
                    } 
                } 
            }
        }

        return dist[m-1][n-1];
    }
}