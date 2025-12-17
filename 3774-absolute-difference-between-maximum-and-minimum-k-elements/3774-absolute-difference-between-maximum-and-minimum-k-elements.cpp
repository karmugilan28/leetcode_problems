class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < k; i++)  sum1 += nums[i];
        sort(nums.rbegin(),nums.rend());
        for(int i = 0; i < k; i++)  sum2 += nums[i];
        return abs(sum1-sum2);
    }
};