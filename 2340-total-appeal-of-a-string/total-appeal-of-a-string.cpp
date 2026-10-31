class Solution {
public:
    long long appealSum(string s) {
        

        /*
        contribution of each char at i technique

        for substring a b c d a b r t a e r a e t l
        for second a, it's contribution to any substring starting at before first 'a' is 0
        as the first 'a' would have already contributed to them

        for endpos , it can be any n-i;

        
        
        */
        int n = s.size();
        int last[26];
        memset(last, -1,sizeof(last));
        
        long long res = 0 ;
        for(int i = 0 ; i < n; i++) {
            long long startPositions = i - last[s[i] - 'a'];
            long long endPositions = n - i;
            // cout<< s[i] << startPositions << ": "<< endPositions<<endl;
            res += startPositions*endPositions;
            
            last[s[i] - 'a'] = i;
            

            
        }

        return res;

    
    }
};