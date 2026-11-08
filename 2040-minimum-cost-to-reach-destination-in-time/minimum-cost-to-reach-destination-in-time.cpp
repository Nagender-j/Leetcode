class Solution {
public:
    using pr = pair<int,int> ;
    using pp = pair<int,pair<int,int>> ;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size() ;

        vector<vector<pr>> adj(n) ;
        for( auto &e : edges ){
            adj[e[0]].push_back({e[1], e[2]}) ;
            adj[e[1]].push_back({e[0], e[2]}) ;
        }
        
        // state -> {node,time} -> what is a cost on a node at perticular time
        vector<vector<int>> dis(n, vector<int>(maxTime+1, 1e9)) ;
        priority_queue<pp, vector<pp>, greater<pp>> pq ; //cost, {time, node}

        dis[0][0] = passingFees[0] ;
        pq.push({passingFees[0],{0,0}}) ;
        while( !pq.empty() ){
            auto [cost, pr] = pq.top() ;
            auto [time, node] = pr ;
            pq.pop() ;

            // there will be all costs with node n-1 whichever has minimal will pop fist
            if( node == n-1 ) return cost ;
            // discard the cost which has higher then previous at same state
            if( cost > dis[node][time] ) continue ;

            for( auto &nbr : adj[node] ){
                int v = nbr.first ;
                int t = nbr.second ;
                int c = passingFees[v] ;

                if( time+t <= maxTime && cost+c < dis[v][time+t] ){
                    dis[v][time+t] = cost+c ;
                    pq.push({cost+c, {time+t, v}}) ;
                }
            }
        }

        int ans = 1e9 ;
        for( int i = 0 ; i<=maxTime ; i++ ){
            ans = min(ans, dis[n-1][i] ) ;
        }
        return ans == 1e9 ? -1 : ans ;

    }
};