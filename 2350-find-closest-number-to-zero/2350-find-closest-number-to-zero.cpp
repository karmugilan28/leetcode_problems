class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini=INT_MAX,res;
        for(int i=0;i<nums.size();i++){
            if(mini>abs(nums[i])){
                mini=abs(nums[i]);
                res=nums[i];
            }
            else if(mini==abs(nums[i]))
                res=max(res,nums[i]);
        }
        return res;
    }
};