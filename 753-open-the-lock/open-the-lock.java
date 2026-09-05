class Solution {
   private char[] getNextDigits(char c)
     {
        char[] res = new char[2];
        if(c == '9') {
            res[0] = '0';
            res[1] = '8';
        } else if(c == '0') {
            res[0] = '1';
            res[1] = '9';
        } else {
            res[0] = (char)(c-1);
            res[1] = (char) (c+1);
        }
        
        return res;
    }
    public int openLock(String[] deadends, String target) {
        Queue<String> q = new LinkedList<>();
        String start = "0000";
        Set<String> vis = new HashSet<>();
        Set<String> deadEnds = new HashSet<>(Arrays.asList(deadends));
        if(deadEnds.contains(start)) return -1;
        q.offer(start);
        vis.add(start);

        int level = 0;
        
        while(!q.isEmpty()) {
            int sz  = q.size();
            while(sz-- > 0) {
                String s = q.poll();
                if(s.equals(target)) return level;
                
                for(int i = 0 ; i < 4; i++) {
                    StringBuilder next = new StringBuilder(s);
                    char[] nextDigits = getNextDigits(s.charAt(i));
                    for(char c : nextDigits) {
                        next.setCharAt(i, c);
                        if(!vis.contains(next.toString()) && !deadEnds.contains(next.toString())) {
                            vis.add(next.toString());
                            q.offer(next.toString());
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
}