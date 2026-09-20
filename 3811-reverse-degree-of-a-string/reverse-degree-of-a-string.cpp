class Solution {
public:
    int reverseDegree(string s) {
        
        int res = 0;
        for(int i = 0 ;i < s.size();i++) {
            int  c = 'z' - s[i] + 1;
            res += (i+1)*c;
        }

        return res;
        
    }
};