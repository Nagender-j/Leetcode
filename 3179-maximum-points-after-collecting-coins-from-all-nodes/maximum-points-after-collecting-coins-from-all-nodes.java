class Solution {
    public int maximumPoints(int[][] edges, int[] coins, int k) {
                
        int n = coins.length;
        List<List<Integer>> adj = new ArrayList<>();
        
        for(int i = 0 ; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // vis = vector<int>(n, false);
        for(int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.get(a).add(b);
            adj.get(b).add(a);
           
        }

        for(int i = 0 ; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
      
        return solve(0, 0, coins, k, adj,-1);
    }

    int [][]dp = new int[100001][15];
    int solve(int node, int cnt, int[] coins, int k, List<List<Integer>> adj, int parent) {

        int pow = 1<<cnt;
        int coinVal = coins[node]/pow;

        if(dp[node][cnt] != -1) return dp[node][cnt];

        int op1 = coinVal - k ;
        int op2 = 0;
        for(int child : adj.get(node)) {
            if(child == parent) continue;
            op1 += solve(child, cnt, coins, k, adj, node);
        }

        if(cnt >=14 ) return dp[node][cnt]  = Math.max(op1, op2);
    
        op2 = coinVal/2;
        for(int child : adj.get(node)) {
            if(child == parent) continue;
            op2 += solve(child, cnt+1, coins, k, adj, node);
        }

        int res = Math.max(op1, op2);
        
        return dp[node][cnt] = res;  
    }
}