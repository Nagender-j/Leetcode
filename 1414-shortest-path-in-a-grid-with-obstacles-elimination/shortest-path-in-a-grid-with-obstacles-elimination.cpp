struct state {
    int x,y,k;
};
class Solution {
public:
    bool vis[41][41][41*41];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int shortestPath(vector<vector<int>>& a, int k) {
        queue<state>q;

        int m = a.size(), n = a[0].size();
        int level = 0;
        
        q.push({0,0,k}); // state = x,y
        vis[0][0][k] = true;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                state item = q.front();q.pop();
                if(item.x == m-1 && item.y == n-1) return level;
                
                for(int i = 0 ; i < 4; i++) {
                    int nx = item.x + dx[i];
                    int ny = item.y + dy[i];
                    if(nx < 0 || nx >= m || ny < 0 || ny >=n ) continue;

                    if(a[nx][ny] == 1) {
                        if(item.k == 0 || vis[nx][ny][item.k-1]) continue;
                        vis[nx][ny][item.k-1] = true;
                        q.push({nx,ny,item.k-1});
                    } else {
                        if(vis[nx][ny][item.k]) continue;
                        vis[nx][ny][item.k] = true;
                        q.push({nx,ny,item.k});
                    }
                    
                }
                
            }

            level++;
        }

        return -1;
    }
};