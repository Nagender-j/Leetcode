class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        int stops = 0;
        // add the last station or else handle it seperately at end 
        if(n == 0 || stations.back()[0] < target) {
             stations.push_back({target, 0});
        }
        

        // so the intuition is it will be beneficial for me to take largest capacity station 
        // when i truely need fuel, so keep all visited stations in pq and take top at need
        // by need i mean min fuel required to reach atleast next stop or target at last stop
        priority_queue<int>pq;
        long long fuel = startFuel;
        int prevLoc = 0; // start at 0;
       
        for(auto station : stations) {
            int curLoc = station[0], capacity = station[1];
            
            // fuel is enough to reach target 
            if(fuel >= target-prevLoc) return stops;

            // distance between previous stop and cur stop
            int distance = curLoc - prevLoc;

            // can't reach cur stop, so take fuel 
            if(fuel < distance) {
              while(fuel < distance && pq.size() > 0) {
                fuel += pq.top(); pq.pop();
                stops++;

              }
              
              // even after taking possible fuel, i still can't reach curStop , so it's not possible 
              if(fuel < distance) return -1;
                
            }

            
            fuel -= distance;
            prevLoc = curLoc;
            pq.push(capacity);

        }

        return stops;
    }
};