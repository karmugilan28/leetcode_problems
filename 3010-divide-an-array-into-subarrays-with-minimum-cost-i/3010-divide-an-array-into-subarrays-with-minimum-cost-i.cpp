class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                int s = (nums[i]+nums[j]);
                mini = min(mini,s);
            }
        }
        
        return sum+mini;
    }
};