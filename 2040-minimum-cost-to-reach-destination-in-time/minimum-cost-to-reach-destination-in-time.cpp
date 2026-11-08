class Solution {
public:

    int inf = 1e9+7;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);

        for(auto edge : edges) {
            int x = edge[0], y = edge[1], time = edge[2];
            adj[x].push_back({y, time});
            adj[y].push_back({x, time});
        }


        vector<vector<int>>cost(n, vector<int>(maxTime+1, inf));
        // pair<int,pair<int,int>>
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({passingFees[0], {0, 0}});
        cost[0][0] = passingFees[0];

        while(!q.empty()) {
          auto item = q.top(); q.pop();
          int costToNode = item.first, node = item.second.first, cumTime = item.second.second;
         
          if(cost[node][cumTime] < costToNode) continue;
          if(node  == n-1) return costToNode;
          
        //   cout<<"THis is for  costToNode : node : cumTime "<<costToNode<<" "<< node <<" "<<  cumTime<<endl;
          for(pair<int,int> child : adj[node]) {
            int newTime = cumTime+child.second;
            if(newTime > maxTime) continue;
            if( (cost[child.first][newTime] > costToNode + passingFees[child.first] )) {
               
                cost[child.first][newTime] = costToNode + passingFees[child.first];
                q.push({cost[child.first][newTime], {child.first, cumTime+child.second}});
                // cout<<"cost : node : cumTime -> "<<cost[child.first] <<" "<< child.first <<" "<< cumTime+child.second<<endl;
            } 
          }

          
        }  

        int res = inf;
        for(int i = 0; i <= maxTime; i++) {
            res = min(res,cost[n-1][i]);
        }
        if(res == inf) return -1;
        return res;
    }
};