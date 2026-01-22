class Solution {
    public int minLength(String s) {
        int n = s.length();
        Stack<Integer>st = new Stack<>();

        for(int i = 0 ; i < n ; i++){

            if(!st.empty() && (s.charAt(st.peek()) == 'A' && s.charAt(i) == 'B' || s.charAt(st.peek()) == 'C' && s.charAt(i) == 'D')){
                st.pop();
            }
            else
                st.push(i);
        }
        return st.size();
    }
}