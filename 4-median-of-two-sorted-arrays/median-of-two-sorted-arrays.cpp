class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int z = n+m;
        vector<int>ans(z , 0);

        int j = 0;
        for(int i = 0 ; i < n ; i++){
            ans[j] = nums1[i];
            j++;
        }
        for(int i = 0 ; i < m ; i++){
            ans[j] = nums2[i];
            j++;
        }
        sort(ans.begin() , ans.end());
        
        double result = 0;
        if(z % 2 != 0){
            result = ans[z/2];
        }
        else{
            int a = z/2;
            result = (ans[a] + ans[a - 1])/2.0;
        }
        return result;
    }
};