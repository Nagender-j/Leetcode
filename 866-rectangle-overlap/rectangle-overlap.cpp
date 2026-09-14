class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
      int x1A = a[0] , x2A  = a[2] , y1A = a[1], y2A = a[3];
      int x1B = b[0] , x2B = b[2],   y1B = b[1], y2B = b[3];
                   
      int xOverlap = max(x1A, x1B) < min(x2A, x2B);
      int yOverlap = max(y1A, y1B) < min(y2A, y2B);

      return xOverlap *1LL* yOverlap > 0;
    }
};