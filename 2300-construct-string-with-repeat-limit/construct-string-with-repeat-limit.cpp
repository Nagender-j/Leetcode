class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int>freq;
        for(char c : s) {
            freq[c]++;
        }


        priority_queue<pair<char,int>> pq;
        for(auto &[ch, f] : freq) {
            pq.push({ch, f});
        }

        string res = "";
        
        while(pq.size()) {
            pair<char, int> first = pq.top(); pq.pop();
            int mxRepeatLimit = repeatLimit;
            if(res.size() && res.back() == first.first) {
                mxRepeatLimit -= 1;
            }
            if(pq.size() == 0) {
                for(int i = 0 ; i < min(first.second, mxRepeatLimit); i++) {
                    res += first.first;
                }

                return res;
            }

            pair<char, int> second = pq.top(); pq.pop();
            

            for(int i = 0 ; i < min(first.second, mxRepeatLimit); i++) {
                    res += first.first;
            }

            res += second.first;
            first.second -= min(first.second, mxRepeatLimit);
            second.second -= 1;
            if(first.second != 0) {
                pq.push({first.first, first.second});
            }

            if(second.second != 0) {
                pq.push(second);
            }
        }
        
        return res;
    }
};