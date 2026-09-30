class Solution {
public:
    unordered_map<int,unordered_set<int>> routeAndStops;
    unordered_map<int, unordered_set<int>> adj;
    int bfs(int source, int dest) {
        if(source == dest) return 0;
        unordered_set<int> vis;
        queue<int> q;
        for(int route : getAllRoutesWithSourceAsAStop(source)) {
            q.push(route);
            vis.insert(route);
        }
        
        int total = 1;
       
        
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int route = q.front(); q.pop();
                if(doesRouteHasDest(route, dest)) {
                    return total;
                }

                for(int childRoute : adj[route]) {
                   
                    if(vis.count(childRoute) == 0) {
                        vis.insert(childRoute);
                        q.push(childRoute);
                    }
                }
            }
            
            total++;
        }

        return -1;
    }

    vector<int> getAllRoutesWithSourceAsAStop(int source) {
        vector<int> routes;
        for(auto [route, stops] : routeAndStops) {
            if(stops.count(source)) {
                routes.push_back(route);
            }
        }
        
        return routes;
    }

    bool doesRouteHasDest(int route, int dest) {
        if(routeAndStops[route].count(dest)) {
            return true;
        } 

        return false;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> stopsAndRoutes;
        for(int i = 0 ; i < routes.size(); i++) {
            vector<int> route = routes[i];
            unordered_set<int> s(route.begin(), route.end());
            routeAndStops[i] = s;

            for(int stop : route) {
                stopsAndRoutes[stop].insert(i);
            }
        }

        // construct adj
        for(auto [stop , routesSet] : stopsAndRoutes) {
            vector<int> routes = convertSetToArray(routesSet);
            for(int i = 0; i < routes.size(); i++) {
                for(int j = i+1; j < routes.size(); j++) {
                    int ri = routes[i], rj = routes[j];
                    adj[ri].insert(rj);
                    adj[rj].insert(ri);
                }
            }
        }

      
        

        return bfs(source, target);
    }

    vector<int> convertSetToArray(unordered_set<int> routes) {
        vector<int> a;
        for(int i : routes) {
            a.push_back(i);
        }

        return  a;
    }
};