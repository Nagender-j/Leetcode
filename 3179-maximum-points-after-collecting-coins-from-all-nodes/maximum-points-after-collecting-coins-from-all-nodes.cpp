class Solution {
public:
    int dp[100001][15];
    int solve(int node, int cnt, vector<int>& coins, int k, vector<vector<int>>& adj, int parent) {

        int pow = 1<<cnt;
        int coinVal = coins[node]/pow;

        if(dp[node][cnt] != -1) return dp[node][cnt];

        int op1 = coinVal - k ;
        int op2 = 0;
        for(int child : adj[node]) {
            if(child == parent) continue;
            op1 += solve(child, cnt, coins, k, adj, node);
        }

        if(cnt >=14 ) return dp[node][cnt]  = max(op1, op2);
    
        op2 = coinVal/2;
        for(int child : adj[node]) {
            if(child == parent) continue;
            op2 += solve(child, cnt+1, coins, k, adj, node);
        }

        int res = max(op1, op2);
        
        return dp[node][cnt] = res;  
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        
        int n = coins.size();
        vector<vector<int>> adj(n);
        // vis = vector<int>(n, false);
        for(auto &edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
           
        }

        memset(dp, -1, sizeof(dp));
      
        return solve(0, 0, coins, k, adj,-1);
    }
};