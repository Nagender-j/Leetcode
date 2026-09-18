class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int>first(26, n+1), last(26, -1);
        for(int i = 0 ; i < n; i++) {
            char c = s[i];
            int idx = c - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = i;
        }

        vector<pair<int,int>> intervals;
        for(int i = 0 ; i < 26; i++) {
            int start = first[i];
            int end = last[i];
            if(start == n+1) continue;
            bool possible = true;

            for(int j = start; j <= end; j++) {
                int insideChar = s[j] - 'a';
                if(first[insideChar] < start) {
                    possible = false;
                    break;
                }

                end = max(end, last[insideChar]);
            }
            
            if(possible) {
                intervals.push_back({start, end});
            }
        }

        sort(intervals.begin(), intervals.end(), [&](auto p, auto q) {
            return p.second < q.second;
        });

        int prevEnd = -1;
        vector<string>res;
        for(auto [l, r] : intervals) {
            if(l > prevEnd ) {
                string itr = s.substr(l,r-l+1);
                res.push_back(itr);
                prevEnd = r;
            }
        }

        return res;
    }
};