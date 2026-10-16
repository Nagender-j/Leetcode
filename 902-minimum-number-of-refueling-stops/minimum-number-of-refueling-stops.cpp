class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        int stops = 0;
        if(n == 0 || stations.back()[0] < target) {
             stations.push_back({target, 0});
        }
        
        priority_queue<int>pq;
        long long fuel = startFuel;
        int prevLoc = 0;
       
        for(auto station : stations) {
            int curLoc = station[0], capacity = station[1];
            
            if(fuel >= target-prevLoc) return stops;

            int distance = curLoc - prevLoc;

            if(fuel < distance) {
              while(fuel < distance && pq.size() > 0) {
                fuel += pq.top(); pq.pop();
                stops++;

              }

              if(fuel < distance) return -1;
                
            }

            
            fuel -= distance;
            prevLoc = curLoc;
            pq.push(capacity);

        }

        return stops;
    }
};