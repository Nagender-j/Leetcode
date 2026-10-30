class Solution {
public:
    long long numOfSubsequences(string s) {
        long long L = 0, T = 0;
        int n = s.size();
        long long totalT = 0;
        
        for(char c : s) {
            if(c == 'T') totalT++;
        }

        long long res = 0;
        // first take all LCT sequences into res
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == 'C') {
                res += L*(totalT - T);
            }

            if(s[i] == 'L'){
                L++;
            } else if(s[i] == 'T') {
                T++;
            }
        }

        L = 0 , T = 0;
        // now find the mxSequence we can get , if i can insert L at begin or T at end or C at any mid pos
        long long op3 = 0;
        long long op1 = 0, op2 = 0;
        for(int i = 0 ; i < n; i++) {
            long long temp=0;
            if(s[i] == 'C') {
                op1 +=  totalT - T;
                op2 += L ;
            }

            temp = L* (totalT-T);
            op3 = max(op3, temp);

            if(s[i] == 'L'){
                L++;
            } else if(s[i] == 'T') {
                T++;
            }
            
        }

        res += max({op1, op2, op3});

        return res;
    }
};