class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int n = stations.length;
        int stops = 0;
        
        if(n == 0) {
             if(startFuel >= target) return 0;
             return -1;
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> Integer.compare(b,a));
        long fuel = startFuel;
        int prevLoc = 0; // start at 0;
       
        for(int[] station : stations) {
            int curLoc = station[0], capacity = station[1];
            
            // fuel is enough to reach target 
            if(fuel >= target-prevLoc) return stops;

            // distance between previous stop and cur stop
            int distance = curLoc - prevLoc;

            // can't reach cur stop, so take fuel 
            if(fuel < distance) {
              while(fuel < distance && !pq.isEmpty()) {
                fuel += pq.peek(); pq.poll();
                stops++;

              }
              
              // even after taking possible fuel, i still can't reach curStop , so it's not possible 
              if(fuel < distance) return -1;
                
            }

            
            fuel -= distance;
            prevLoc = curLoc;
            pq.add(capacity);

        }

        if(stations[n-1][0] < target) {
            if(fuel >= target-prevLoc) return stops;
            int distance = target - prevLoc;
            if(fuel < distance) {
              while(fuel < distance && !pq.isEmpty()) {
                fuel += pq.peek(); pq.poll();
                stops++;

              }
              
              // even after taking possible fuel, i still can't reach curStop , so it's not possible 
              if(fuel < distance) return -1;
                
            }

        }

        return stops;
    }
}