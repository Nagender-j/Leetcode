class Solution {
public:
    int uniqueLetterString(string s) {
        // think in terms of the contribution of the current char, in all the substrings possible
        // a char CH can contribute 1 to all start points before the first nearest C to left and right
        // nearest is taken because if we take that index also as start or end or the idx before that
        // then that particualr CH will be the contributer, and our cur CH might not be the sole contributor 
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