class Solution {
public:
    vector<int>dp;
    int dfs(int node, vector<int>& quiet, vector<vector<int>>&adj) {
        
        if(dp[node] != -1) return dp[node];
        int qValue = quiet[node];
        for(int child : adj[node]) {
            
            qValue = min(qValue, dfs(child, quiet, adj));
        }

        return dp[node] = qValue;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>adj(n+1);
        for(auto entry : richer) {
            int a = entry[0], b = entry[1];
            adj[b].push_back(a);
        }

        dp = vector<int>(n, -1);
        map<int,int> quietValToNode;
        for(int i = 0; i< n;i++) {
            quietValToNode[quiet[i]] = i;
        }

        vector<int>res(n);
        for(int i = 0 ; i < n; i++) {
            dfs(i, quiet, adj);
        }

        for(int i = 0 ;i < n; i++) {
            res[i] = quietValToNode[dp[i]];
        }
        return res;
    }
};