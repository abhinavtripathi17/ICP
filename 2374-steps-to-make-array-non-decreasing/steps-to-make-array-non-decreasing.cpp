class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int , int>>st;

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            int steps = 0;

            while(!st.empty() && st.top().first <= nums[i]){
                steps = max(steps , st.top().second);
                st.pop();
            }

            if(!st.empty()) steps++;

            ans = max(ans , steps);

            st.push({nums[i] , steps});

        }
        return ans;

    }
};