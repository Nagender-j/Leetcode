class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(char c : s.toCharArray()) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if(c == ')') {
               if(!match(st, '(')) return false;
               st.pop();
            } else if(c == '}') {
               if(!match(st, '{')) return false;
               st.pop();
            } else if(c == ']') {
               if(!match(st, '[')) return false;
               st.pop();
            } 
        }

        return st.size() == 0;
    }

    boolean match(Stack<Character> st, char c) {
        if(!st.isEmpty() && st.peek() == c) return true;

        return false;
    }
}