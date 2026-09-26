class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        StringBuilder res = new StringBuilder();
       
        Map<String, String> mp = new HashMap<>();

        for(List<String> l : knowledge) {
            mp.put(l.get(0), l.get(1));
        }

        int n = s.length();
        for(int i = 0 ; i < n; ) {
            char c = s.charAt(i);
            if(c == '(') {
                i++;
                StringBuilder cur = new StringBuilder();
                while(i< n && s.charAt(i) != ')') {
                    cur.append(s.charAt(i));
                    i++;
                }
                String value = "?";
                if(mp.containsKey(cur.toString())) {
                    value = mp.get(cur.toString());
                }
                res.append(value);
                
            } else {
                res.append(c);
            }

            i++;
        }

        return res.toString();
    }
}