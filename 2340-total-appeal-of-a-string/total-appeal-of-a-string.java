class Solution {
    public long appealSum(String s) {
         
        int n = s.length();
        int[] last = new int[26];
        Arrays.fill(last, -1);
        
        long res = 0 ;
        for(int i = 0 ; i < n; i++) {
            long startPositions = i - last[s.charAt(i) - 'a'];
            long endPositions = n - i;
            // cout<< s[i] << startPositions << ": "<< endPositions<<endl;
            res += startPositions*endPositions;
            
            last[s.charAt(i) - 'a'] = i;
            

            
        }

        return res;

    }
}