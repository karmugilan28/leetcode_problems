class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ct = n;
        for(int i = 0; i < n-1; i++){
            ct--;
            vector<int>arr(n);
            for(int j = 0; j < ct; j++){
                arr[j] = (nums[j]+nums[j+1])%10;
            }
            nums = arr;
        }
        return nums[0];
    }
};