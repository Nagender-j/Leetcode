class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int>s(a.begin(), a.end());
        
        int res = 0;
        for(int num : s) {
            if(s.count(num-1)) continue; // only start at begining of sequence;

            int cnt = 1;
 
            while(s.count(num+1)) {
                num = num+1;
                cnt++;
            }

            res = max(res, cnt);
        }

        return res;
        
    }
};