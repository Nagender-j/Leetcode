struct Item {
    int start;
    int type;
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& a) {

        vector<Item> items;
        for(auto i : a) {
            items.push_back({i[0], 0});
            items.push_back({i[1], 1});
        }      

        sort(items.begin(), items.end(), [&](auto p, auto q) {
            if(p.start != q.start) return p.start < q.start;
            return p.type > q.type;
        });
        int mxRooms = 0;
        int curCnt = 0 ;
        for(auto item : items) {
            if(item.type == 0) curCnt++;
            else {
                curCnt--;
            }
            
            mxRooms = max(mxRooms, curCnt);
        }

        return mxRooms;
    }
};