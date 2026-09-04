struct state{
    int node, mask;
};
class Solution {
public:
    bool vis[12][1<<12];
        
    int bfs(vector<vector<int>>adj) {
        int n = adj.size();
        queue<state> q;
        int allVis =  (1<<n) - 1;
        for(int i = 0 ; i < n; i++) {
            q.push({i, 1<<i}); // state is (node, all nodes visited including cur node);
            vis[i][1<<i] = true;
        }
        
        int level = 0;
        while(q.size()) {
            int sz = q.size();
            //   cout<<"This is level : "<< level<<endl;
            while(sz--) {
                state ele = q.front(); q.pop();
                
                int node = ele.node, mask = ele.mask;
              
                // cout<<node<<" "<< bitset<4>(mask)<<endl;
                
                if(mask == allVis) return level;

                for(int child : adj[node]) {
                    int nmask  = mask | 1<<child;
                    if(!vis[child][nmask]) {
                        vis[child][nmask] = true;
                        q.push({child, nmask});
                    }
                }
            }
         
            level++;
        }

        return -1;
        
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        for(int i = 0; i < n; i++) {
            for(int node : graph[i]) {
                adj[i].push_back(node);
                adj[node].push_back(i);                
            }
        }
        

        return bfs(adj);
    }
};