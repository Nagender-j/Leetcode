
struct state {
    int x, y,mask;
};
class Solution {
public:
    bool vis[30][30][1<<6];
    int keyId[30][30];
    map<int,pair<int,int>> keyPos;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int bfs(int sx,int sy, vector<string> &a, int mask, int k) {
        queue<state>q;
        vis[sx][sy][mask] = true;
        q.push({sx,sy,mask});
        int m = a.size();
        int n = a[0].size();

        int allTaken = (1<<k)-1;

        int level = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                state e = q.front(); q.pop();
                if(e.mask == allTaken) return level;
                //
                for(int i = 0; i < 4; i++) {
                    int nx = e.x+dx[i];
                    int ny = e.y+dy[i];
                    int nmask = e.mask;
                    if(nx < 0 || nx>=m || ny<0 || ny>=n || a[nx][ny] == '#') continue; // invalid
                    
                    if(a[nx][ny] >='A' && a[nx][ny] <= 'Z') { // it's a lock
                        pair<int,int> key = keyPos[a[nx][ny] - 'A'];
                        int pos = keyId[key.first][key.second]; // check if key is collected already if not continue
                        if((nmask & (1<<pos)) == 0) continue; // key not collected for lock so continue
                    } else if(a[nx][ny] >='a' && a[nx][ny] <= 'z') { // it's a key collect it 
                        int pos = keyId[nx][ny];
                        nmask |= (1<<pos);
                    }

                    if(vis[nx][ny][nmask]) continue;
                    
                    vis[nx][ny][nmask] = true;
                    q.push({nx,ny,nmask});


                }
            }
            level++;
        }

        return -1;
    }
    int shortestPathAllKeys(vector<string>& a) {
        int m = a.size();
        int n = a[0].size();
        
        int sx,sy;
        int k = 0;
        for(int i = 0; i < m ;i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == '@') {
                    sx = i;
                    sy = j;
                } else if(a[i][j] >='a' && a[i][j] <='z') {
                    keyId[i][j] = k++;
                    keyPos[a[i][j] - 'a'] = {i,j};
                }
            }
        }

        return bfs(sx,sy,a,0,k);
    }
};