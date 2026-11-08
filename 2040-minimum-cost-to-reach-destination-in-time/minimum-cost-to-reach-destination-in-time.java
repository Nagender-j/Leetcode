class Solution {
    int inf = (int)1e9+7;
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int n = passingFees.length;
        // vector<vector<pair<int,int>>> adj(n);
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0 ;i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge : edges) {
            int x = edge[0], y = edge[1], time = edge[2];
            
            adj.get(x).add(new int[]{y, time});
            adj.get(y).add(new int[]{x, time});
           
        }

        int[][] cost = new int[n][maxTime+1];
        for(int i = 0 ; i < n; i++) {
            Arrays.fill(cost[i], inf);
        }

        PriorityQueue<int[]> q = new PriorityQueue<>((a,b) -> Integer.compare(a[0], b[0]));
        q.offer(new int[]{passingFees[0], 0, 0});
        cost[0][0] = passingFees[0];

        while(!q.isEmpty()) {
          int[] item = q.poll();
          int costToNode = item[0], node = item[1], cumTime = item[2];
         
          if(cost[node][cumTime] != costToNode) continue;
          if(node  == n-1) return costToNode;
          
        //   cout<<"THis is for  costToNode : node : cumTime "<<costToNode<<" "<< node <<" "<<  cumTime<<endl;
          for(int[] child : adj.get(node)) {
            int newTime = cumTime+child[1];
            if(newTime > maxTime) continue;
            if( (cost[child[0]][newTime] > costToNode + passingFees[child[0]] )) {
               
                cost[child[0]][newTime] = costToNode + passingFees[child[0]];
                q.offer(new int[]{cost[child[0]][newTime], child[0], cumTime+child[1]});
                // cout<<"cost : node : cumTime -> "<<cost[child.first] <<" "<< child.first <<" "<< cumTime+child.second<<endl;
            } 
          }

          
        }  

        int res = inf;
        for(int i = 0; i <= maxTime; i++) {
            res = Math.min(res,cost[n-1][i]);
        }
        if(res == inf) return -1;
        return res;
    }
}

