class Solution {
    public int longestConsecutive(int[] nums) {
       
        Set<Integer> s = new HashSet<>();
        for(int i : nums) s.add(i);
        
        int res = 0;
        for(int num : s) {
            if(s.contains(num-1)) continue; // only start at begining of sequence;

            int cnt = 1;
 
            while(s.contains(num+1)) {
                num = num+1;
                cnt++;
            }

            res = Math.max(res, cnt);
        }

        return res;
    }
}