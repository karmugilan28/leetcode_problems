class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0],maxi=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                sum+=nums[i+1];
                maxi=max(maxi,sum);
            }
            else{
                sum=nums[i+1];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};