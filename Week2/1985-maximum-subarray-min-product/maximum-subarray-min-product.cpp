class Solution {
public:
    int maxSumMinProduct(vector<int>& arr) {
         int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<long long>p_sum(n , 0);
        vector<int>left(n , 0);
        vector<int>right(n , 0);
        stack<int>st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // for(int i = 0 ; i < n ; i++){
        //     cout << left[i];
        // }
        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1 ; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        p_sum[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            p_sum[i] = arr[i] + p_sum[i-1];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long sum = p_sum[right[i] - 1] -
                           (left[i] == -1 ? 0 : p_sum[left[i]]);
            ans = max(ans, sum * arr[i]);
        }
        

        return ans % MOD;
    }
};