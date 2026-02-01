class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        vector<int>arr;
        for(int i = 1; i < n; i++)
            arr.push_back(nums[i]);
        
        sort(arr.begin(),arr.end());

        return sum+arr[0]+arr[1];
    }
};