class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        int i = 0;
        while(i < n-2){
            if(nums[i] == 0){
                ops++;
                nums[i] = 1 ^ nums[i];
                nums[i+1] = 1 ^ nums[i+1] ;
                nums[i+2] = 1 ^ nums[i+2];
            }
            i++;
        }
        return nums[n-2] == 0 || nums[n-1] == 0 ? -1 : ops;


        return ops;

    }
};