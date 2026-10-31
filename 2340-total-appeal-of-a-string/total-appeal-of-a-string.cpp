class Solution {
public:
    long long appealSum(string s) {
        
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