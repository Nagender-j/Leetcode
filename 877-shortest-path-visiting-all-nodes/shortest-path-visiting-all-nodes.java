class Solution {
      private int bfs(List<List<Integer>> adj) {
        int n = adj.size();
        Queue<int[]> q  = new LinkedList<>();
        int allVis =  (1<<n) - 1;
        boolean [][] vis = new boolean[n][1<<n];

        for(int i = 0 ; i < n; i++) {
            q.offer(new int[]{i, 1<<i}); // state is (node, all nodes visited including cur node);
            vis[i][1<<i] = true;
        }
        
        int level = 0;
        while(!q.isEmpty()) {
            int sz = q.size();
            //   cout<<"This is level : "<< level<<endl;
            while(sz-- > 0) {
                int[] ele = q.poll();
                
                int node = ele[0], mask = ele[1];
              
                // cout<<node<<" "<< bitset<4>(mask)<<endl;
                
                if(mask == allVis) return level;

                for(int child : adj.get(node)) {
                    int nmask  = mask | (1<<child);
                    if(!vis[child][nmask]) {
                        vis[child][nmask] = true;
                        q.offer(new int[]{child, nmask});
                    }
                }
            }
         
            level++;
        }

        return -1;
        
    }
    public int shortestPathLength(int[][] graph) {
        List<List<Integer>> adj = new ArrayList<>();
        int n = graph.length;
        for(int i = 0 ; i < n; i++) {
            adj.add(new ArrayList<>());
        }

         for(int i = 0; i < n; i++) {
            for(int node : graph[i]) {
                adj.get(i).add(node);
                adj.get(node).add(i);                
            }
        
        }
        
        return bfs(adj); 

    }
}