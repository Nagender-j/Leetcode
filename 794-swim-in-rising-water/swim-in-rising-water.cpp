struct Node{
  int x,y,time;  
};

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int inf = 1e9+7;
    bool vis[51][51][50*50];
    int swimInWater(vector<vector<int>>& g) {
        memset(vis, false, sizeof(vis));
        int n = g.size();
        vector<vector<int>> dist(n, vector<int>(n, inf));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({g[0][0], 0, 0});
        dist[0][0] = g[0][0];
        while(!q.empty()) {
          vector<int> node = q.top(); q.pop();
          int wt = node[0], x = node[1], y = node[2];
          if(dist[x][y] < wt) continue;
          for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=0 && nx<n && ny>=0 && ny<n) {
               if(dist[nx][ny] > max(wt, g[nx][ny])) {
                dist[nx][ny] = max(wt, g[nx][ny]);
                q.push({max(wt, g[nx][ny]), nx, ny});
               }
               
            } 
          }
        }  

        return dist[n-1][n-1];  
    }
};