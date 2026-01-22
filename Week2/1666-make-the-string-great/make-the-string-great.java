class Solution {
    public String makeGood(String s) {
        int n = s.length();
        Stack<Integer>st = new Stack<>();

        for(int i = 0 ; i < n ; i++){
            if(!st.empty() && (Math.abs(s.charAt(i) - s.charAt(st.peek())) == 32)){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        String str = "";


        while(!st.empty()){
            str += s.charAt(st.pop());
        }

        String x = "";
        for(int i = str.length() - 1 ; i >= 0 ; i--){
            x += str.charAt(i);
        }
        return x;

    }
}