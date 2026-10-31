class Solution {
public:
    int uniqueLetterString(string s) {
        
        int n = s.size();
        vector<int>nearestToLeft(n,-1);
        vector<int> nearestToRight(n, n);

        unordered_map<char, int> left, right;

        for(int i = 0 ; i < n; i++) {
            char c = s[i];
            if(left.count(c)) {
                nearestToLeft[i] = left[c];
            }

            left[c] = i;
           
        }

        for(int i = n-1; i>=0; i--) {
            char c = s[i];
            if(right.count(c)) {
                nearestToRight[i] = right[c];
            }

            right[c] = i;
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            int start = i-nearestToLeft[i];
            int end = nearestToRight[i] - i;
            res += start*end;
        }

        return res;
    }
};