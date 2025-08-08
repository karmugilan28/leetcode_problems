class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int res = INT_MAX;
        if(n == 1)  return nums[0];
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] > nums[l] && nums[mid] > nums[r]){
                res = min(res,min(nums[r],nums[l]));
                l = mid;
            }
            else{
                res = min(res,(nums[l],min(nums[r],nums[mid])));
                r = mid;
            }
        }
        return res;
    }
};