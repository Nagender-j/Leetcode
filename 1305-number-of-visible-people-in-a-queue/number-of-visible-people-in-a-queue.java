class Solution {
    public int[] canSeePersonsCount(int[] a) {
        int n = a.length;
        int[] res = new int[n];
        Stack<Integer> s = new Stack<>();
        for(int i = n-1; i >=0 ; i--) {
            int cnt = 0;
            while(!s.isEmpty() && s.peek() <= a[i]) {
                s.pop();
                cnt++;
            }

            if(s.isEmpty()) {
                res[i] = cnt;
            } else {
                res[i] = cnt+1;
            }

            s.push(a[i]);
        }

        return res;
        
    }
}