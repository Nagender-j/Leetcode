class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

      vector<pair<int,int>> coveringArea;
      for(int i = 0 ; i < ranges.size(); i++) {
        coveringArea.push_back({i-ranges[i], i+ranges[i]});
      }

      sort(coveringArea.begin(), coveringArea.end());

      int taps = 0;
      int pointToBeCovered = 0 ;
      
      for(int i = 0 ; i < coveringArea.size(); ) {
        int maxAreaCovered = -1;

        int j;
        for(j = i; j < coveringArea.size(); ) {
            if(coveringArea[j].first <= pointToBeCovered) {
                maxAreaCovered = max(maxAreaCovered, coveringArea[j].second);
                j++;
            } else {
                break;
            }
        }
        
        // we got a best tap which covers point, so take it 
        if(maxAreaCovered > pointToBeCovered) {
            taps++;
        }
         // all garden covered
         if(maxAreaCovered >= n) return taps;
        // no point to cover after pointTObecovered
        if(maxAreaCovered == -1) return -1;
        
        // update point to be covered for next iteration and also i
        pointToBeCovered = maxAreaCovered;
        i = j;
        
        
      }
      
      if(n > pointToBeCovered) return -1;
      return taps;
    }
};