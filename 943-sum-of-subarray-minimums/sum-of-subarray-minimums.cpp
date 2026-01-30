class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int>pse(n , 0);
        vector<int>nse(n , 0);
        stack<int>st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // for(int i = 0 ; i < n ; i++){
        //     cout << pse[i] << ' ';
        // }

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);

        }
        // for(int i = 0 ; i < n ; i++){
        //     cout << nse[i] << ' ';
        // }
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            ans = (ans + (long long)left * right * arr[i]) % MOD;
        }

        return (int)ans;
    }
};