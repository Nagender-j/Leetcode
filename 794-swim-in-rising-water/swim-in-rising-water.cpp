struct Node{
  int x,y,time;  
};

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool vis[51][51][50*50];
    int swimInWater(vector<vector<int>>& g) {
        memset(vis, false, sizeof(vis));
        int n = g.size();
        queue<Node>q;
        q.push({0,0, g[0][0]});
        vis[0][0][g[0][0]] = 1;

        int res = n*n;

        while(!q.empty()) {
            Node node = q.front(); q.pop();
            int x = node.x, y = node.y, time = node.time;
           
            if(x == n-1 && y== n-1) {
                res = min(res, time);
            }
            
            for(int dir = 0 ; dir < 4; dir++) {
                int nx = x+dx[dir];
                int ny = y+dy[dir];
                if(nx>=0 && nx <n && ny>=0 && ny <n && !vis[nx][ny][max(time, g[nx][ny])]) {
                     vis[nx][ny][max(time, g[nx][ny])] = 1;
                    q.push({nx, ny, max(time, g[nx][ny])});
                }
            }        
        
        }  

        return res;      
    }
};