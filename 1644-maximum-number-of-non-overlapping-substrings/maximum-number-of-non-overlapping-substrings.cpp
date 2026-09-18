class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // 1. Find first and last occurrence of every character
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        // 2. Generate valid minimal intervals
        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                // This character started before our interval.
                // Therefore this interval cannot be valid.
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of x.
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // 3. Interval scheduling:
        //    Pick intervals that finish earliest.
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};