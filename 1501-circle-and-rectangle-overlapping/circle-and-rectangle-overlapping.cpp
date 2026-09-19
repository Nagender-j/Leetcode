class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        for(int i = y1 ; i <= y2; i++) {
            if(distance(xCenter, yCenter, x1, i) <= radius*radius || distance(xCenter, yCenter, x2, i) <= radius*radius ) {
                return true;
            }
        }

         for(int i = x1 ; i <= x2; i++) {
            if(distance(xCenter, yCenter, i, y1) <= radius*radius || distance(xCenter, yCenter, i, y2) <= radius*radius ) {
                return true;
            }
        }

        if(xCenter>=x1 && xCenter<=x2 && yCenter>=y1 && yCenter <=y2) return true;

        return false;

    }

    long long distance(int x1,int y1, int x2, int y2) {
        int dx = x2-x1;
        int dy = y2-y1;
        return dx*dx + dy*dy;
    }
};