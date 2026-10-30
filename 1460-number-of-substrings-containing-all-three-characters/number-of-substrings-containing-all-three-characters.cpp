class Solution {
public:
    bool isSatisfied(int freq[]) {
        for(int i = 0; i < 3; i++) {
            if(freq[i] <= 0) return  false;
        }

        return  true;
    }
    int numberOfSubstrings(string s) {
        int freq[3] = {0};
        
        int res = 0;
        int i = 0, j= 0 , n=s.size();

        while(j < n) {
            int idx = s[j] - 'a';
            freq[idx]++;
            if(!isSatisfied(freq)) {
                j++;
                continue;
            }

            // i to j has satisfied to every k from j to n-1 can be end of subarray where start is i

            //abcabc

            res += n - j;
            while(i < n) {
                freq[s[i] - 'a']--;
                i++;
                if(isSatisfied(freq)) {
                    res += n-j;
                } else {
                    break;
                }
            }

            j++;

        }

        return res;
    }
};