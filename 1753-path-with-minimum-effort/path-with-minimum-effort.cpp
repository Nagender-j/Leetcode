class Solution {
public:
    int inf = 1e8;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, inf));
        pq.push({0, 0, 0}); 
        dist[0][0] = 0;
        
        while(!pq.empty()) {
            vector<int> node = pq.top(); pq.pop();
            int pathAbsDiff = node[0], x = node[1], y = node[2];
            if(dist[x][y] < pathAbsDiff) continue;
            for(int dir = 0 ; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx>=0 && nx<m && ny>=0 && ny<n) {
                    int curAbsDiff = max(pathAbsDiff, abs(heights[nx][ny] - heights[x][y]));
                    if(dist[nx][ny] > curAbsDiff) {
                        dist[nx][ny] = curAbsDiff;
                        pq.push({curAbsDiff, nx, ny});
                        
                    } 
                } 
            }
        }

        return dist[m-1][n-1];

    }
};