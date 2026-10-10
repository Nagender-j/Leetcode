class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>&a) {
        sort(a.begin(), a.end(), [&](auto p, auto q) {
            if(p[1] != q[1]) return p[1] < q[1];
            return p[0] < q[0];
        });

        int prevEnd = -1e9;
        int cnt = 0;
        for(auto i : a) {
            if(i[0] < prevEnd) {
                cnt++;
            } else {
                prevEnd = i[1];
            }
        }
        
        return cnt;
    }
};