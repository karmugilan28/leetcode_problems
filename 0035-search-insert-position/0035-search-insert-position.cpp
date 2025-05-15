class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int res;
        for(int i=0;i<n;i++){
            if(nums[i]==target) return i;
            if(nums[i]>target){
                res=i;
                break;
            }
        }
        return res;
    }
};