class Solution {
    boolean [][][] vis = new boolean[41][41][41*41];
    int []dx = new int[] {-1,0,1,0};
    int []dy = new int[] {0,1,0,-1};
    public int shortestPath(int[][] a, int k) {
        Queue<int[]> q = new LinkedList<>();

        int m = a.length;
        int n = a[0].length;
        int level = 0;
        
        q.offer(new int[]{0,0,k}); // state = x,y
        vis[0][0][k] = true;
        while(q.size() > 0) {
            int sz = q.size();
            while(sz-- > 0) {
                int[] item = q.poll();
                if(item[0] == m-1 && item[1] == n-1) return level;
                
                for(int i = 0 ; i < 4; i++) {
                    int nx = item[0] + dx[i];
                    int ny = item[1] + dy[i];
                    if(nx < 0 || nx >= m || ny < 0 || ny >=n ) continue;

                    if(a[nx][ny] == 1) {
                        if(item[2] == 0 || vis[nx][ny][item[2]-1]) continue;
                        vis[nx][ny][item[2]-1] = true;
                        q.offer(new int[]{nx,ny,item[2]-1});
                    } else {
                        if(vis[nx][ny][item[2]]) continue;
                        vis[nx][ny][item[2]] = true;
                        q.offer(new int[]{nx,ny,item[2]});
                    }
                    
                }
                
            }

            level++;
        }

        return -1;
    }
}