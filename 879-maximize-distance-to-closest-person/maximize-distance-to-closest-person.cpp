class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>a;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 1) {
                a.push_back(i);
            }
        }

        int mxDistance = -1;
        for(int i = 1; i < a.size(); i++) {
            mxDistance = max(mxDistance, (a[i] - a[i-1])/2);
        }



        if(seats[0] == 0) {
            mxDistance = max(mxDistance, a[0]);
        }
         if(seats.back() == 0) {
            mxDistance = max(mxDistance, (int)seats.size()-1 - a[a.size()-1]);
        }

        return mxDistance;
    }
};